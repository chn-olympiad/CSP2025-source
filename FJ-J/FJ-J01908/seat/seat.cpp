#include<bits/stdc++.h>
using namespace std;

int n,m,k,x,c,r;
int a[110];

bool cmp(int x,int y){return x>y;} 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;k=n*m;
	cin>>a[1],x=a[1];
	for(int i=2;i<=k;i++)
		cin>>a[i];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++)
		if(a[i]==x){x=i;break;}
	c=(x-1)/n+1;
	if(c%2==1) r=(x-1)%n+1;
	else r=n-(x-1)%n;
	cout<<c<<" "<<r;
	return 0;
} 
