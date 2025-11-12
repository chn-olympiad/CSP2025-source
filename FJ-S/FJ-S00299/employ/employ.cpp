#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[10000]={},b[10000]={},c[10000]={};
void todo(){
	int vis[10000]={};
	for(long long i=1;i<=n;i++){
		vis[b[i]]++;
	}for(long long i=1;i<=n;i++){
		if(!vis[i])return;
	}long long pd=0,pd1=0;
	for(long long i=1;i<=n;i++){
		if(a[i]==0){
			pd++;
			continue;
		}if(pd>=c[b[i]]){
			pd++;
			continue;
		}pd1++;
	}if(pd1>=m){
		ans++;
		ans%=998244353;
	}return;
}
void dg(long long x){
	if(x>n){
		todo();
		return;
	}for(long long i=1;i<=n;i++){
		b[x]=i;
		dg(x+1);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		a[i+1]=s[i]-'0';
	}for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	dg(1);
	ans%=998244353;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
