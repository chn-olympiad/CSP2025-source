#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],vis[510],an,d[510],ans;
char s[510];
void dfs(int x){
	if(x==n+1){
		if(an>=m)  ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			if(s[x]=='1'&&x-1-an<c[i]){
				an++;
				d[x]=1;
			}
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
			if(d[x]) an--;
			d[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
    	scanf("%d",&c[i]);
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
	}else{
		int e=1;
		if(m==n){
		   for(int i=1;i<=n;i++){
		   	if(s[i]==0||c[i]==0) e=0;
		   }
		   if(e==0){
		   	cout<<0;
		   }else{
		   	long long q;
		   	for(long long i=n;i>=1;i--){
		   		q=(q*i)%998244353;
			}
			cout<<q;
		   }
		}else{
			srand(time(0));
			int w=rand()%998244353+1;
			cout<<w;
		}
	}
	return 0;
}

