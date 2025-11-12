#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
struct node{
	int u,v,w;
}a[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool p=true;
	cin>>n>>m>>k;
	int i,j;
	for(i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int c,s;
	for(i=1;i<=k;i++){
		cin>>c;
		for(j=1;j<=n;j++){
			cin>>s;
			if(s!=0) p=0;
		}
	}
	if(p==1&&k!=0){
		cout<<0;
		return 0; 
	}
	sort(a+1,a+n+1,cmp);
	int sum=0;
	for(i=1;i<n;i++){
		sum+=a[i].w;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
