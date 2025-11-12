#include<iostream>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b[200005],c,sum=0,sun=0;
	cin>>a>>c;
	for(int i=1;a>=i;i++)
	{
		cin>>b[i];
		if(b[i]==1)
		{
			sum++;
		}
		if(b[i]==0)
		{
			sun++;
		}
	}
	if(c==1)
	{
		cout<<sum;
	}
	if(c==0)
	{
		cout<<sun;
	}
	return 0;
}
