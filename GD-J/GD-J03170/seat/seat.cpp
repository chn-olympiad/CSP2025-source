#include<bits/stdc++.h>
using namespace std;
int n,m,cur=1;
struct node{
	int sco,id;
}a[1005];
bool cmp(node x,node y){
	return x.sco>y.sco;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].sco, a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++,cur++)
				if(a[cur].id==1) cout<<j<<' '<<i,exit(0); 
		}else{
			for(int i=n;i>=1;i--,cur++)
				if(a[cur].id==1) cout<<j<<' '<<i,exit(0); 
		}
	}
	return 0;
}
