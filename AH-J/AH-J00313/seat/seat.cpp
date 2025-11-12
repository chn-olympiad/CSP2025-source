#include<bits/stdc++.h>
using namespace std;
struct ks{
	int cj;
}x[105];
bool cmp(ks a,ks b){
	return a.cj>b.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,bh,h,l,c;
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>x[i].cj;
		bh=x[1].cj;
	}
	sort(x+1,x+b+1,cmp);
	for(int i=1;i<=b;i++){
		if(x[i].cj==bh)c=i;
		
	}
	l=(c-1)/m+1;
	if(l%2==1){		
		if(l==1)h=c;
		else h=c%n;
	}
	else h=n+1-c%n;
	cout<<l<<' '<<h;
	return 0;
}
