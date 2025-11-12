#include<bits/stdc++.h>
using namespace std;
int a[120];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	c=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==c){
			c=i;
			break;
		}
	int x,y;
	if(c%n!=0){
		x=c/n+1;
	}
	else{
		x=c/n;
	}
	if(x%2==0){
		if(c%n!=0)
			y=n-c%n+1;
		else
			y=1;
	}
	else{
		if(c%n!=0)
			y=c%n;
		else
			y=n;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}

