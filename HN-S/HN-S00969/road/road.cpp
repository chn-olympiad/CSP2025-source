#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}s[100001];
int c[100001],a[1001][100001],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
		ans+=s[i].w;
	} 
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0) cout<<ans;
	return 0;
} 
//Ren5Jie4Di4Ling5%
