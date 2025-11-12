#include<bits/stdc++.h>
#define ff(i,n) for(int i=1;i<=n;i++) 
#define int long long
using namespace std;
const int N=2e4+10,M=1e6,mod=993644353; 
int i,j,k,n,m,x,y,tot;
struct node{
	int s,id;
}e[N];
bool cmp(node a,node b){
	return a.s>b.s;
}
main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ff(i,n*m){
		cin>>x;
		e[++tot]={x,i};
	}
	sort(e+1,e+1+tot,cmp);
	int pos=0;
	ff(i,tot)if(e[i].id==1){
		pos=i;
		break;
	}
	int x,y;
	x=ceil(pos*1.0/n);y=(x%2?pos-(x-1)*n:n-(pos-(x-1)*n)+1);
	cout<<x<<' '<<y;
}
