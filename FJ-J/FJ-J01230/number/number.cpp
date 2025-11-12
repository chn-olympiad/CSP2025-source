#include<bits/stdc++.h>
using namespace std;
int n,a[10],o,x;
char l[1000026];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>l;
	n=strlen(l);
	for(int i=0;i<n;i++)
	{
		o=l[i];
		if(o<=57)
		{
			a[o-48]+=1;
			x++;
		}	
	}
	if(x==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			cout<<i;
			a[i]--;
		}
	}
}
