#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
string s;
int a[510];
int u[510];
void go(int zh,int cnt,int f){
	if(zh==n){
		if(cnt>=m){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(u[i]==0){
			if(a[i]<=f||s[zh]=='0'){
				u[i]=1;
				go(zh+1,cnt,f+1);
				u[i]=0;
			}else{
				u[i]=1;
				go(zh+1,cnt+1,f);
				u[i]=0;
			}
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	memset(u,0,sizeof(0));
	go(0,0,0);
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 