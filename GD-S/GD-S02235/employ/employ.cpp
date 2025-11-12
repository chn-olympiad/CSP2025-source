#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
int inf=998244353;
string s1;
bool b=true,f=true;
int  a[N],i,j,n,m,c[N],an,p,ans,v[N];
void dfs(int s,int d){
	f=false;
	if(s1[d-1]=='1'&&a[s]>c[d]){
		an++;
		f=true;
	}
	if(d==n){
		if(an>=m) ans++;
		return;
	}
	for(i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(i,d+1);
			v[i]=0;
		}
	}
	if(f) ans--;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	cin>>n>>m;
	cin>>s1;
	p=n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i]) p--;
	} 
	for(i=1;i<=n;i++){
		c[i]=c[i-1];
		if(s1[i-2]=='0') c[i]++;
	} 
	if(m>p){
		cout<<0;
		return 0;
	}
	an=0;
	for(i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		v[i]=1;
		dfs(i,1);
		v[i]=0;
	}
	cout<<an;
	return 0;
}
