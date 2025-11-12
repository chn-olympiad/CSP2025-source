#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 998244353
#define N 100005
#define M 500005
#define quickly ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n,m,c[505],k[505],ans,t[505],no[505],nx[505],C[505][505];
string s;
int main(){
	quickly;
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin >>n>>m>>s;
	ans=1;
	for(int i=0;i<=n;i++)
		C[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	for(int i=1;i<=n;i++)
		cin >>c[i],nx[c[i]]++;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(k[i-1]>c[i] || s[i-1]=='0'){
			k[i+1]=k[i]+1,t[i]=t[i-1];
		}else {
			t[i]=t[i-1]+1,k[i+1]=k[i];
		}
		no[i]=n;
	}
	no[n+1]=n;
	if(t[n]<m){
		cout<<0<<endl;
		return 0;
	}
	for(ll i=1;i<=n;i++)
		no[k[i]]=min(i,no[k[i]]);
	for(int i=1;i<=n;i++){
		if(nx[i])
			ans=(ans*max((ll)(1),C[no[i]-nx[i-1]][nx[i]]))%mod;
		nx[i]+=nx[i-1];
	}
	cout<<ans<<endl;
	
	return 0;
}
/*
luogu1250410ίχ 
//freopen("xxxx.in","r",stdin);
//freopen("xxxx.out","w",stdout);
feropen("xxxx.in","r",stdin);
feropen("xxxx.out","w",stdout);
freopen("xxxx.in","w",stdin);
freopen("xxxx.out","r",stdout);
stostostostostostostostostostostostostostosto ccf CCF orzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorz
slove
cin<<
cout>>
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
*/

