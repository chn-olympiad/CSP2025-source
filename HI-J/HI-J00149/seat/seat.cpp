#include<bits/stdc++.h>
using namespace std;
int mp[15][15];
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int d=n*m;
	for(int i=1;i<=d;i++){
		cin>>a[i];
	}
	int g=a[1];
	sort(a+1,a+1+d,cmp);
	int cnt;
	for(int i=1;i<=d;i++){
		if(g==a[i]) cnt=i;
	}
	int c,r;
	if(cnt%n==0) c=cnt/n;
	else c=cnt/n+1; 
	if(c==1) cout<<c<<' '<<cnt;
	else{
		int num;
		num=cnt-(c-1)*n;
		if(c%2!=0) r=num;
		else r=n-num+1;
		cout<<c<<' '<<r;
	}
	return 0;
}

