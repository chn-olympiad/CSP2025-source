#include<bits/stdc++.h>
using namespace std;
struct node{
	int mar;
	int num;
}in[105];
int n,m,tmp,xzb,yzb;
bool cmp(node a,node b){
	return a.mar>b.mar;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>tmp;
		in[i].mar=tmp;
		in[i].num=i;
	}
	sort(in+1,in+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(in[i].num==1) tmp=i;
	}
	xzb=tmp/n+(tmp%n!=0);
	if(xzb%2==0)yzb=(m+1)-tmp+(xzb-1)*m;
	else yzb=tmp-(xzb-1)*m;
	cout<<xzb<<" "<<yzb;
	return 0;
}

