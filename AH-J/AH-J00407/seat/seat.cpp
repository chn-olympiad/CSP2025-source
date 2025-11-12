#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id;
	int data;
};
bool cmp(node n1,node n2){
	return n1.data>n2.data;
}
node a[105];
int ans[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].data;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int cn=1,cm=1;
	for(int i=1;i<=n*m;i++){
		ans[cn][cm]=a[i].id;
		if(cm%2==1){//down
			if(cn==n){
				cm++;
			}else{
				cn++;
			}
		}else{//up
			if(cn==1){
				cm++;
			}else{
				cn--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==1){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
