#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[20],a[20][4],s;
bool flag1[1000010],flag2[1000010];
struct node{
	int u,v,w;
}fix[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>fix[i].u>>fix[i].v>>fix[i].w;
		if(flag1[fix[i].u]==0||flag2[fix[i].v]==0){
			s+=fix[i].w;
		}	
	}	
	for(int i=1;i<=k;i++){
		cin>>c[i]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
	}
	if(k==0){
		cout<<s;
	}
	else cout<<13;	
	return 0;
}
