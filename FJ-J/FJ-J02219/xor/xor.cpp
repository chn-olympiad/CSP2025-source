#include <bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N],n,k;
int _xor(int x,int y){
	if(x==y) return a[x];
	int ans=a[x];
	for(int i=x+1;i<=y;i++){
		ans=ans^a[i];
	}
	return ans;
}
int f(int l,int r){
	int cnt=0;
	int cnttmp;
	if(l==r) return 1;
	for(int i=l+1;i<=r;i++){
		for(int j=l+1;j<=i;j++){
			//cout<<"("<<j<<","<<i<<")"<<"---"<<_xor(j,i)<<"\n";
			if(_xor(j,i)==k){
				cnttmp=f(i,r)+1;
			}
			cnt=max(cnt,cnttmp);
		}
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*if(k==0){
		cout<<n;
		return 0;
	}*/
	cout<<f(1,n);
}