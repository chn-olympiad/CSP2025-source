#include<bits/stdc++.h>
using namespace std;
int n,m,ans,p=998244353,a[505],kl=0,fg[505],sum=0,c[505],flag;
char s[505];
void dfs(int x){
	if(x==n+1){
		if(sum>=m)
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!fg[i]){
			int fag=0;
			if(a[x]==0||kl>=c[i]){
				kl++,fag=1;	
			} 
			else sum++;
			fg[i]=1;
			//sum++;
			dfs(x+1);
			//sum--;
			fg[i]=0;
			if(fag)kl--;
			else sum--;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') flag=1;
		a[i]=s[i]-'0';
		//cout<<a[i]<<endl;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans%p<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


