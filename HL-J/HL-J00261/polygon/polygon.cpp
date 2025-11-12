#include<bits/stdc++.h>
using namespace std;
const int F=1000;
int a[F],xorr[F];
int ss=0;
int n;
int dfs(int p,int ma,int su,int k){
	if(p>=n&&ma*2<su&&k>2)
	{
		ss++;
		return 0;
	}if(p>=n)
	{
		return 0;
	}
	dfs(p+1,max(ma,a[p]),su+a[p],k+1);
	dfs(p+1,ma,su,k);
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	if(n==3){
		int maxx=max(a[0],max(a[2],a[3]));
		if(maxx*2<a[1]+a[2]+a[3])
		cout<<1;
		else cout<<0;
	}
	else if(n<3){
		cout<<0;
	}
	else cout<<ss;
}//     