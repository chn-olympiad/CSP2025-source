#include<bits/stdc++.h>
using namespace std;
int n,m,pj;
char ss[505];
int c[505];
bool b[505];
int a[505];
const int o=998244353;
void dfs(int s){
	if(s==n+1){
		int j=0,mm=0;
		for(int i=1;i<=n;i++){
			if(j>=c[a[i]]||ss[i]=='0'){
				j++;
			}else{
				mm++;
			}
		}
		if(mm>=m)
			pj++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			a[s]=i;
			dfs(s+1);
			b[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>ss[i];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<pj%o;
	return 0;
} 
