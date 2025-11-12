#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1],flag=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		flag++;
		if(x==a[i])break;
	}
	int xx=ceil(flag*1.0/n),yy;
	if(xx%2==1){
		if(flag%n==0)yy=n;
		else yy=flag%n;
	}
	else{
		if(flag%n==0)yy=1;
		else yy=n-flag%n+1;
	}	
	cout<<xx<<" "<<yy<<endl;
	return 0;
}
