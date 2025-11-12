#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],sum,s[5010],dp[5010][5010];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int last,int fir,int sums){
	if(sums+s[n]-s[last]<=2*a[fir])return ;
	if(sums>2*a[fir]&&fir!=0){
		sum++;
		sum%=998244353;
	}
	if(x==n)return ;
	for(int i=last+1;i<=n;i++){
		if(fir==0)dfs(x+1,i,i,a[i]);
		else dfs(x+1,i,fir,sums+a[i]);
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	dfs(0,0,0,0);
	cout<<sum;
	return 0;
}//help me!##F!
//please give me 340
//it's very important for me for the reason that i am a nine grade student
//in order to go to GDFZ to achieve my dream ,i must get enough prize
//if you give me 340,i will orz you
//luogu uid 1129279
//by liangcha_crush_ly

