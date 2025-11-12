#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const int MOD=998244353;
int n,a[N],s[N],maxx=-1;
ll ans;
void dfs(int x){
	for(int i=2;i<=(1<<(x-1));i++){
		int tmp=i,num=x-1,cnt=0,sum=0;
		while(tmp){
			if(tmp&1)sum+=a[num],cnt++;
			num--,tmp>>=1;
		}
		if(sum>a[x]&&cnt>=2)ans++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	if(maxx==1){
		ll num=1;
		for(int i=1;i<=n;i++)num=(num<<1)%MOD;
		ans=num-(n*n+n+2)/2;
	}else{
		for(int i=2;i<=n;i++)
			if(s[i]>2*a[i])dfs(i);
	}
	cout<<ans;
	return 0;
}
