#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+5;
int n,m,k,t=0;
struct aa{
	LL u,v,w;
}a[N];
LL b[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n+1;i++){
			cin>>b[j][i];
			if(b[j][i]==0)t++;
		}
	}
	if(t==k+k*n && k!=0)cout<<0;
	/*else if(k==0){
		
	}*/
	return 0;
}
