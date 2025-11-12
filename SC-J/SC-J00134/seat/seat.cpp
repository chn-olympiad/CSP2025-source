#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int rfen,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rmc=0;
	int fenshu[225];
	int zuowei[15][15];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>fenshu[i];
	rfen=fenshu[1];
	sort(fenshu+1,fenshu+m*n+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(fenshu[i]==rfen) rmc=i;
	int x;
	double y;
	x=rmc%n;
	y=(double)rmc/n;
	//cout<<y;
	int b=y;
	//cout<<b;
	if(b!=y)
		y=b+1;
	int bb=y;
	//cout<<bb;
	if(x==0) x=n;
	if(bb%2) k++;
	else
		x=n+1-x;
	cout<<bb<<" "<<x;
	return 0;
}// 4 4 87 100 99 98 97 96 95 94 93 92 91 90 89 88 86 85
//3 3 94 95 96 97 98 99 100 93 92