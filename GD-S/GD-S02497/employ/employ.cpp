#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
char a[1145];
int c[1145],b[1145];
bool pd[1145];
int ca,t=1;
void dfs(int p){
	if(p==n+1){
		t=1;ca=0;
		for(int i=1;i<=n;i++){
			if(a[t]=='0'){
				ca++;t++;
			} 
			else{
				if(c[b[i]]<=ca)ca++;
				else t++;
			}
		}
		if(n-ca>=m){
		ans++;	
		ans%=998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(pd[i]==0){
			pd[i]=1;
			b[p]=i;
			dfs(p+1);
			pd[i]=0; 
		}
	}
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
int lovemiaomiao;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	cin>>c[i];
}
dfs(1);
cout<<ans;
return 0; 
}
/*
 10 5
 1101111011
 6 0 4 2 1 2 5 4 3 3
*/
