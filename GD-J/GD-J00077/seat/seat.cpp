#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],xm,xb,nb,cb;
bool cmp(int v,int b){
	return b<v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
		cin>>a[i];
	xm=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==xm){
			xb=i;
			break;
		}
	}
	if(xb%m==0)
		nb=xb/m;
	else
		nb=xb/m+1;
	if(nb%2==0)
		cb=(n-(xb-(nb-1)*m))+1;
	else
		cb=(xb-(nb-1)*m);
	cout<<nb<<" "<<cb;
	return 0;
}
