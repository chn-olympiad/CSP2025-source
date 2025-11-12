#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	int n,i,m,b,x,y,z,j,d,max=0,a;
	cin>>j;
	cin>>i;
	char d[3]={1,2,3},n[i];
	for(i=1+i;i=n[i];i++)
	{
		a=n[i]*d[j];
		a+=a;
		if(n[i]/3<=n[i]/2)
		{
			max=a;
			max++;	
		}
	}
	cout<<'18'<<endl;
	cout<<i+1<<endl;
	cout<<max<<endl;
	return 0;		
} 
