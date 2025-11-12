#include <bits/stdc++.h>
using namespace std;

int n,m,x,p,r,c;

struct data1{
	int num,id;
}a[110];

bool cmp(data1 x,data1 y){ return x.num>y.num; }

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i=1; i<=n*m; i++)  cin >> x, a[i]={x,i};
	
	sort(a+1,a+n*m+1,cmp);
	
	for (int i=1; i<=n*m; i++)
		if(a[i].id==1)  p=i;
	
	c=(p-1)/n+1;
	
	if(p%(2*n)>=1 && p%(2*n)<=n)  r=(p-1)%n+1;
	else  r=n-(p-1)%n;
	
	cout << c << " " << r;
	
	return 0;
}
