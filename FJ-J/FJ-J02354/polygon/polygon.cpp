#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum,a[10000],flag[10000],b[10000],t,fl=1;
map<string,int> mp;
void dfs(int cnt,int cd,int ma,int la){
	if(cnt==n+2) return;
	if(cnt>=3&&cd>ma*2){
		string s;
		for(int i=1;i<=t;i++){
			s+=char(b[i]+'0');
			s+=" ";
		}
		if(mp[s]==0){
			sum++;
			mp[s]=1;
			sum%=998244353;
		}
	}
	for(int i=la+1;i<=n;i++){
		b[++t]=i;
		int p=max(a[i],ma);
		dfs(cnt+1,cd+a[i],p,i);
		t--;
		dfs(cnt,cd,ma,i);
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fl=0;
	}
	if(fl){
		int zds=0;
		for(int i=3;i<=n;i++){
			int js=1,js1=1;
			for(int j=1;j<=i;j++){
				js1*=j;
				js1%=998244353;
				js*=(n-j+1);
				js%=998244353;
			}
			zds+=js/js1;
			zds%=998244353;
		}
		cout<<zds%998244353;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<sum;
	return 0;
}
