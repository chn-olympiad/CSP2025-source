#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110][110];
struct p{
	long long a,b;
}s[10010];
void dfs(long long x,long long y,long long k){
	if(a[x][y]==0){
		return;
	}
	if(s[k].b==1){
		cout<<y<<" "<<x;
		return;
	}
	if(y%2&&a[x+1][y]!=0){
		dfs(x+1,y,k+1);
		return;
	}else if(y%2==0&&a[x-1][y]!=0){
		dfs(x-1,y,k+1);
		return;
	}else{
		dfs(x,y+1,k+1);
		return;
	}
}
int cmp(p a,p b){
	return a.a>b.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=1;
		}
	}
	for(long long i=0;i<n*m;i++){
		cin>>s[i].a;
		s[i].b=0;
	}
	s[0].b=1;
	sort(s,s+n*m,cmp);
	dfs(1,1,0);
	return 0;
} 