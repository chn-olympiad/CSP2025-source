#include <bits/stdc++.h>
using namespace std;
int c[510],h[510]={0},a[510],v[510]={0};
int n,m,k;
string s;
int ans=0;
void dfs(int x)
{
	if(x>n){
		int temp=0;
		for(int i=1;i<=n;i++){
			if(!s[a[i]]){
				temp++;
				continue;
			}
			if(i-h[a[i]]>=c[a[i]]){
			 temp++;continue;} 
		}
		if(temp<=k){
			//for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		//	cout<<endl;
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			a[x]=i;
			dfs(x+1);
			v[i]=0;
			a[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	k=n-m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	int f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!=1) f=0;
		h[i]=h[i-1]+s[i]-'0';
	}
	dfs(1);
	cout<<ans<<endl;
	/*
	if(f==1){
		int k=n-m;
		for(int i=1;i<=n;i++) 
			if(c[i]==0)  
	}
	*/
	return 0;
}

