#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m;
struct node{
	int vl,id;
}a[N*N];

bool cmp(node a,node b){
	if(a.vl==b.vl) return a.id<b.id;
	return a.vl>b.vl;
}

int get(){
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1) return i;
	}
	return -1;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].vl;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int x=get();
	cout<<(x-1)/n+1<<" ";
	if(((x-1)/n+1)%2==1) cout<<(x-1)%n+1;
	else cout<<(n-((x-1)%n+1)+1);
	return 0;
}

