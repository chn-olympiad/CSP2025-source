#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,id;
	int x,y;
}q[1005];
bool cmp(node x,node y){
	return x.a>y.a;
}bool cnp(node x,node y){
	return x.id<y.id;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>q[i].a;
		q[i].id=i;
	}sort(q+1,q+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int d=(i-1)*m+j;
			q[d].x=i;
			if(i%2==1){
				q[d].y=j;
			}else{
				q[d].y=m-j+1;
			}
		}
	}sort(q+1,q+n*m+1,cnp);
	cout<<q[1].x<<' '<<q[1].y;
	return 0;
}
