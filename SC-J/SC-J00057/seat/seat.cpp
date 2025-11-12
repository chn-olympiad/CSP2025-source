#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15],b[105];
struct node{
	int b;
	int val;
}c[105];
bool cmp(node x,node y){
	return x.b>y.b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i].b;
		c[i].val=i;
	}
	sort(c+1,c+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				int cnt=(i-1)*n+j;
				if(c[cnt].val==1){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				int cnt=(i-1)*n+j;
				if(c[cnt].val==1){
					cout<<i<<" "<<n-j+1<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}