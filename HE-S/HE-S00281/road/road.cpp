#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
int pp;
//struct node{
//	int u,v,w;
//}a[N];
//struct nodeq{
//	int uu,vv,ww;
//}b[N];
int a[N][N];
int w,p,s,cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>w>>p>>s;
		a[w][p]=s;
	}
	for(int i=2;i<=n;i++){
		cnt+=a[1][i];
	}
	cout<<cnt;
	return 0;
}
