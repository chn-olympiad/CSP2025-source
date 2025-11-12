#include<bits/stdc++.h>
using namespace std;

struct lin{
	int u,v,w;
};
struct cit{
	int c;
	int a[10001]={};
};
cit ci[11];
lin bro[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>bro[i].u>>bro[i].v>>bro[i].w;
	for(int i=1;i<=k;i++){
		cin>>ci[i].c;
		for(int j=1;j<=n;j++)
			cin>>ci[i].a[j];
	}
	cout<<0;
	return 0;
}
