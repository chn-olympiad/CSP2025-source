#include<bits/stdc++.h>
using namespace std;
int n,m,s[505],c[505],cnt;
bool b[505];
void dfs(int p,int d,int mem){
	if(p>=m){
		cnt=(cnt+mem)%998244353;
	}
	if(s[d]&&d<=n){
		for(int i=d;i<=n;i++){
			if(c[i]!=0){
				dfs(p+1,d+1,c[i]*mem%998244353);
			}
			else{
				dfs(p,d+1,mem);
			} 
		}
	}
	else{
		dfs(p,d+1,mem);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n+1;i++){
		char ch;
		scanf("%c",&ch);
		s[i]=int(ch)-48;
	}
	for(int i=1;i<=n;i++){
		int ch;
		scanf("%d",&ch);
		c[ch]++;
	}
	dfs(0,0,1);
	cout<<cnt;
	return 0;
}

