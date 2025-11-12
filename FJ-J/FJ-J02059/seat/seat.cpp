#include<bits/stdc++.h>
using namespace std;
bool cmp(int w,int q)
{
	return w>q; 
} 
int n,m,r; 
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++)
	{ 
		cin>>a[i];
	} 
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x; 
	for(int i=1;i<=n*m;i++)
	{ 
		 if(r==a[i])
		 {
		 	x=i;
			break; 
		 }	 
	}
	int y=x/n;
	if(x%n==0)
	{
		cout<<y<<" "<<n;
		return 0;
	}
	y++;
	if(y%2==0){
		cout<<y<<" "<<n-(x%n)+1; 
		return 0; 
	}
	cout<<y<<" "<<x%n<<endl;
	return 0;
}
