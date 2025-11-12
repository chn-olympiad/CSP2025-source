#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,seat;
	int a[N],b[N];
	cin>>n>>m;
	int p=n*m;
	for(int i=1;i<=p;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+0,b+p,cmp);
	for(int i=1;i<=p;i++)
	{
		if(a[1]==b[i]){
			seat=i;
			break;
		}
	}
	int x,y;
	if(seat%n!=0){
		x=seat/n+1;
		if(x%2==0){
			y=n-(seat%n-1);
		}
		else y=seat%n;
	}
	else{
		x=seat/n;
		if(x%2==0) y=1;
		else y=n;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 