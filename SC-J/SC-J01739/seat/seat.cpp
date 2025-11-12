#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int num;
}a[101];
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++tot].num;
		}
	}
	a[1].id=1;
	sort(a+1,a+1+n*m,cmp);
	int l=0;
	
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			l=i;
		//	cout<<l<<' ';
			break;
		}
	}
	int w=l/n;
	int r=l%n;
	if(r)w++;
	int q=0;
	if(w&1){
		q=r;
		if(r==0)
			q=n;
	}
	else{
		q=n-r+1;
		if(r==0)
			q=1;
		
	}
	cout<<w<<' '<<q;
	return 0;
}