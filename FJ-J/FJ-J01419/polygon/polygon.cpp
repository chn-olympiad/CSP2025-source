#include<iostream>
using namespace std;
int n,sum,num,maxj=-111;
int a[5005];
int maxk(int a,int b)
{
	if(a>b)return a;
	else return b;
}
void dpp(int i,int l,int p,int m)
{
	if(i==0){
		sum=(sum+bool(p>2*m))/*%998244353*/;
	}
	else{
		for(int j=l;j<=n-i+1;j++)
		{
		//	cout<<j<<' ';
			dpp(i-1,j+1,p+a[j],maxk(m,a[j]));
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	/*if(n>=100){
		for(int i=3;i<=n;i++)
		{
			sum+=n-i+1;
		}
		cout<<sum;
		return 0;
	}*/
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		//cout<<endl<<i<<endl;
		dpp(i,1,0,-1);
	}
	cout<<sum;
	return 0;
 } 
