#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
string s;
int a[520];
bool vis[520];
void dfs(int cnt,int x,int y){
	if(cnt>n){
		if(x>=m){
			ans++;
		}
		return;
	}
	if(n-y<m){
		return;
	}
	int z[520],j=0,q=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&y>=a[i]){
			vis[i]=1;
			z[j]=i;
			j++;
			q++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[cnt-1]=='0'){
				dfs(cnt+1,x,y+1+q);
			}
			else{
				dfs(cnt+1,x+1,y+q);
			}
			vis[i]=0;
		}
	}
	for(int i=0;i<j;i++){
		vis[z[i]]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			f=0;
			break;
		}
	}
	if(f){
		int sum=1;
		for(int i=n;i>=1;i--){
			sum*=i;
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
