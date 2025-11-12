#include<bits/stdc++.h>
using namespace std;
int n;
long long fa=0;
int c[5005];
int a[5005];
bool b[5005];
void dfs(int id){
	if(id==n+1){
		int s=0;
		for(int i=1;i<=n;i++) s+=c[a[i]];
		if(s>2*c[a[n]]) fa++;
		return; 
	}
	for(int i=a[id-1];i<=n;i++){
		if((i==0)||(i!=0&&b[i]==false)){
			a[id]=i;
			b[i]=true;
			dfs(id+1);
			b[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	dfs(1);
	printf("%lld",fa%998244353);
	return 0;
} 
