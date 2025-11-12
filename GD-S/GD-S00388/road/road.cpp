
#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[1005];
bool cmp(node a,node b){
	return a.c<b.c;
}
int b[1005][1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(b,0x3f,sizeof b);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=m;j++){
			int y;
			cin>>y;
			b[i][j]=min(b[i][j],x+y);
		}
	}
	
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=m-1;i++){
		if(b[a[i].a][a[i].b]<a[i].c){
			ans+=b[a[i].a][a[i].b];
		}else{
			ans+=a[i].c;
		}
	}
	
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
}
