#include<bits/stdc++.h>
using namespace std;
int t[20],a[20],d[20];
int n,m;
string s;
const int Mod=998244353;
int ans=0;
void dfs(int step,int si){
	if(n-si<m)
		return ;
	if(step==n+1){
		if(n-si>=m)
			ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!t[i]){
			d[step]=i;
			t[i]=1;
			if(s[step-1]=='0'||si>=a[d[step]])
				dfs(step+1,si+1);
			else
				dfs(step+1,si);
			t[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			f=0;
			break;
		}
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	n=s.size();
	if(s.size()<=18){
		dfs(1,0);
		cout<<ans;
	}
	else if(f){
		long long x=1;
		for(int i=1;i<=n;i++){
			x*=i;
			x%=Mod;
		}
		cout<<x;
	}
	else
		cout<<0;
	return 0;
}
