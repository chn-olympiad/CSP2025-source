#include<iostream>
using namespace std;

int n,m,k;

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>m>>k;
	int u,v,w,maxx=-1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		maxx=max(maxx,w);
	}
	
	cout<<maxx;

	return 0;
}
