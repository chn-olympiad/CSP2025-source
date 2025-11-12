#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,nm;
struct node{int z,id;}a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;++i) cin>>a[i].z,a[i].id=i;
	sort(a+1,a+1+nm,[](node q,node w){return q.z>w.z;});
	int x=1,y=1,sum=1;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			if(a[sum].id==1) cout<<y<<" "<<x,exit(0);
			sum++;
			if(y&1) x++;
			else x--;
		}
		y++;
		if(y&1) x=1;
		else x=n;
	}
}
