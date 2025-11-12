#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define eb emplace_back
const int N=510;
int n,m,c[N],p[N];
bool vis[N];
char a[N];
inline void dfs(int x){
	if(a[x]=='0') dfs(x+1);
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			
		}
	}
}
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,a+1);
	for(int i=1;i<=n;++i) scanf("%d",&c[i]),p[i]=i;
	do{
		int s=0;
		for(int i=1;i<=n;++i){
			if(s,)
		}
	}while(next_permutation(p+1,p+1+n));
	return 0;
}

