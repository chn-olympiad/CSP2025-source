#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct node{
	int a,id;
}c[N];
bool cmp(node a,node b){
	return a.a>b.a;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,tot=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[++tot].a;
			c[tot].id=tot;
		}
	}
	sort(c+1,c+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		if(c[i].id==1){
			int t=(i-1)/n+1;
			cout<<t<<' ';
			int tt=i-(t-1)*n;
			if(t%2==0){
				tt=n-tt+1;
			}
			cout<<tt<<'\n';
			return 0;
		}
	}
	return 0;
}
