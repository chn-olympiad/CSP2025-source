#include <bits/stdc++.h>
using namespace std;
const int MAXN=505,mod=998244353;
int n,m,c[MAXN],numo,flag[25],wz[25],sone[25],pzer[25],chs[25],ans;
string s;
long long jc[505];
void dfs(int now){
	if(now==numo+1){
		long long ans=1;//3e5+
		for(int i=1;i<=numo;i++){
			pzer[i]=pzer[i-1]+(!flag[i]);
		}
		for(int i=numo;i>=1;i--){
			sone[i]=sone[i+1]+flag[i];
		}
		for(int i=numo;i>=1;i--){
			if(flag[i]==1){
				ans*=n-(upper_bound(c+1,c+n+1,wz[i]-1+pzer[i])-c)-sone[i+1];
			}
		}
		for(int i=numo;i>=1;i--){
			if(flag[i]==0){
				ans*=lower_bound(c+1,c+n+1,wz[i]-1+pzer[i-1])-c-pzer[i+1];
			}
		}
		return ;
	}
	flag[now]=0;
	dfs(now+1);
	flag[now]=1;
	dfs(now+1);
}
void dfsx(int now){
	if(now==n+1){
		int ct=0,num=n;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||ct>=c[chs[i]]){
				num--;
				ct++;
			}
		}
		ans+=(num>=m);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			chs[now]=i;
			flag[i]=1;
			dfsx(now+1);
			flag[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	s='#'+s;
	if(n<=10){
		dfsx(1);
		cout<<ans;
		return 0;
	}
	int tsa=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			tsa=0;
		}
		if(s[i]=='1'){
			wz[++numo]=i;
		}
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		if(!tsa){
			cout<<0;
		}
		else{
			cout<<jc[n];
		}
	}
	else if(numo<=18){
		if(m>numo){
			cout<<0;
		}
		else{
			dfs(1);
		}
	}
	else if(tsa){
		int ct=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				ct++;
			}
		}
		if(n-ct<m){
			cout<<0;
		}
		else{
			cout<<jc[n];
		}
	}
	else if(1){
		
	}
	return 0;
}
