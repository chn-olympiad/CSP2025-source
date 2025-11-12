#include<bits/stdc++.h>
using namespace std;
int n,m,p[505],vis[505],ans=0;
string s;
void f(int x,int y,int num){
	if(num>=m&&x==n)
		ans=(ans+1)%998244353;
	if(x==n||y>n-m)
		return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(p[i]<=y||s[x]=='0'){
				vis[i]=1;
				f(x+1,y+1,num);
				vis[i]=0;
			}
			else{
				vis[i]=1;
				f(x+1,y,num+1);
				vis[i]=0;				
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	f(0,0,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

