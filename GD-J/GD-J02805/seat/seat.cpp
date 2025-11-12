#include<bits/stdc++.h>
using namespace std;
struct node{
	int data,f;
}a[50005];
node mp[505][505];
int top;
bool cmd(node a,node b){
	return a.data>b.data;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].data;
		a[i].f=i;
	}
	sort(a+1,a+1+n*m,cmd);
	for(int i=1;i<=m;i++) {
		if(i%2==0) for(int j=n;j>0;j--) mp[j][i]=a[++top];
		else for(int j=1;j<=n;j++) mp[j][i]=a[++top];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j].f==1){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
