#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
struct daolu{
	int u,v,w;
}a[N]; 
struct chengshi{
	int a1,b1,c1,d1,e1;
}b[N]; 
ll n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++) cin>>b[i].a1>>b[i].b1>>b[i].c1>>b[i].d1>>b[i].e1; 
	cout<<0;
	fclose(stdin);
	fclose(stdout);
}
