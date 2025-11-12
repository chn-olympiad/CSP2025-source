#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n,k;
long long s[N],a[N];
int er(int x){
	if(x==0)return 0;
	return x%2+er(x/2)*10;
}
bool solve(int l,int r){
	int x=s[l],y=s[r],ans=0,cnt=1,t=0;		//求区间异或和 
	while(x!=0 || y!=0){
		int dx=x%2,dy=y%2;
		if(dx==1)t=0;
		else t=1;
		if(dy==1){
			ans+=t*cnt;
		}else{
			ans+=dx*cnt;
		}
		cnt*=2;
		x/=2;
		y/=2;
	}
	if(ans==k)return true;
	else return false;
}
int func(int l,int r,int sum){
	if(l==n && l==r){
		if(a[l]==k);
		return sum+1;
	}
	if(l>r||r>n)return sum;

	if(solve(l-1,r)){

		return func(r+1,r+1,sum+1);
	}else{
		return max(func(l+1,r,sum),func(l,r+1,sum));
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^a[i-1];
	}int ysf=func(1,1,0);
	cout<<ysf;
}
