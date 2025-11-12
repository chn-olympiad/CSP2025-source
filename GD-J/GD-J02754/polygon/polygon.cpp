//T4
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,mx=5000;
int n,a[50007],d[5007][5007],dmx[5007];//d[i][j]=到i总和为j的方案数  dmx[i]=到i总和超过mx的方案数
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	d[0][0]=1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		for(int j=0;j<=mx;++j){
//			d[i][j]+=d[i-1][j]; 
//			if(j>=a[i]) d[i][j]+=d[i-1][j-a[i]];
//			d[i][j]%=mod;
			d[i][j]+=d[i-1][j];
		}
		dmx[i]+=dmx[i-1]*2;
		for(int j=0;j<=mx;++j){
			if(j+a[i]<=mx){
				d[i][j+a[i]]+=d[i-1][j];
				d[i][j+a[i]]%=mod;
			}else{
				dmx[i]+=d[i-1][j];
				dmx[i]%=mod;
			}
		}
//		for(int j=mx+1-a[i];j<=mx;++j){
////			cout<<i<<"\n";
//			dmx[i]+=d[i-1][j];
//			dmx[i]%=mod;
//		}
	}
//	for(int i=1;i<=n;++i){
////		for(int j=0;j<=15;++j){
////			cout<<d[i][j]<<" ";
////		}
//		cout<<d[i][5000]<<" ";
//		cout<<"dmx: "<<dmx[i]; 
//		cout<<'\n';
//	}
	int ans=0;
	for(int i=3;i<=n;++i){
		for(int j=a[i]+1;j<=mx;++j){
			ans+=d[i-1][j];
			ans%=mod;
//			if(d[i-1][j]!=0) cout<<j<<" "<<d[i-1][j]<<" : ";
		}
		ans+=dmx[i-1];
		ans%=mod;
//		cout<<tans-ans<<"\n";
	}
	cout<<ans;
	return 0;
}




























//int mian() feropen( //freopen( froepen( polygen ploygon fropen( int y1,x1,y2,x2; reutrn 0; return O;
//我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会 
//我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会
//我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会
//我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会
//我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会
//我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会我不会
//棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木
//棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木棍木 
//我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了
//我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了
//我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了
//我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了
//我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了
//我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了我会了 
