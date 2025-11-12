#include<bits/stdc++.h>
using namespace std;
int a[1000000];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int group;
	group=2*n;
	int ming;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(i==0) ming=a[i];
	}
	
//	cout<<ming<<endl;
	
	int place;
	sort(a,a+m*n);
//	for(int i=m*n-1;i>=0;i--)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	int cnt=0;
	for(int i=m*n-1;i>=0;i--)
	{
		cnt++;
	   if(a[i]==ming)
	   {
	   	   place=cnt;
	   	   break;
	   }
	}
//	cout<<place<<endl;
	int mod;
	int shang;
	mod=place%group;
	shang=place/group;
	int x;
	int y;
//	cout<<shang<<endl;

	if(mod<=n&&mod!=0)
	{
	   x=2*shang+1;
	   y=mod;
	}
	if(mod==0)
	{
		x=2*shang;
		y=1;
	}
	else if(mod>=n+1)
	{
		 x=2*shang+2;
		 y=2*n+1-mod;
	}
	cout<<x<<" "<<y;
	
}
