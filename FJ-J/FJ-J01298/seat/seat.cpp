#include<bits/stdc++.h>
using namespace std;
const int N=101;
struct node{
	int id,s;
}a[N];
bool cmp(node a,node b){return a.s>b.s;}
int n,m,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[i].id=i;
		cin>>a[i].s;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			r=i;
		}
	}
	int i=(r-1)/n+1;
	if(i&1){
		int j=r%n;
		if(j==0)j=n;
		cout<<i<<' '<<j;
	}else{
		int j=r%n;
		if(j==0)j=n;
		j=n+1-j;
		cout<<i<<' '<<j;
	}
	return 0;
}

