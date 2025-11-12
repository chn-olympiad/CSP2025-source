#include<iostream>
#include<algorithm>
using namespace std;
int n,m,c,r,t,y,a;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int temp=n*m;
	cin>>a;
	t=1;
	for(int i=1;i<n*m;i++){
		cin>>y;
		if(a<y)t++;
	}
	c=(t-1)%(n*2)+1;
	if(c>n){
		c=n-c+n+1;
	}
	r=(t-1)/n+1;
	cout<<r<<' '<<c;
	return 0;

} 
