#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,a[N],num=0;
long long xorr(int l,int r){
	if(r==l) return a[r];
    if(r-l==1) return a[l]^a[r];
    int mid=(l+r)>>1;
    return xorr(l,mid)^(mid+1,r);
}
bool check(int l,int r){
	//cout<<l<<" "<<r<<endl;
	for(int i=l;i<=r;i++){
		if(i==k) return false;
		for(int j=i;j<=r;j++){
			if(xorr(i,j)==k&&(i!=l||j!=r)) return false;
		}
	}
	return true;
}
void dfs(int l,int r){
	if(check(l,r)){//当区间分无可分时num++; 
		num++;
		//cout<<l<<" "<<r<<endl; 
		return;
	}
	int left=l,right=l;
	while(right<r){
		while(a[left]==0&&k!=0){
		    left++;
		    right++;
		}
		while(xorr(left,right)!=k){
			if(right==r){
				right=left+1;
				left++;
			}
			else{
				right++;
			}
		}
		dfs(left,right);
		left=right+1;
		right=left; 
	}
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,n);
	cout<<num<<endl;
	return 0;
}
