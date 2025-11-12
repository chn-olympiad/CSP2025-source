#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,maxx=0,b[4],ni,flag=0;
struct Node{
	int lc,k;
}a[N][4];
bool cmp(Node a,Node b){
	return a.k>b.k;
}
void dfs(int x,int sum){
	if(flag==15000000) return;
	if(x==n+1) {
		maxx=max(maxx,sum);
		flag++;
		return;
	}
	for(int i=1;i<=3;i++){
		if(b[a[x][i].lc]<ni){
			b[a[x][i].lc]++;
			sum+=a[x][i].k;
			dfs(x+1,sum);
			sum-=a[x][i].k;
			b[a[x][i].lc]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(b,0,sizeof(b));
		cin>>n;
		ni=n/2;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				cin>>a[i][j].k;
				a[i][j].lc=j;
			}
		for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+4,cmp);
 	dfs(1,0);
		cout<<maxx<<endl;
		maxx=0;
		flag=0;
	}
	return 0;
} 
