#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("numder.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int num=0,i=0,a[1000001],b,j;
	
	cin>>s;
	while(i<=1000001)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num++;
		a[i+1]=(int(s[i])-48);
		}
		i++;
	}
	for(i=2;i<=num;i++)
	{
		for(j=1;j<num;j++)
		{
		if(a[j]>a[i]||a[j]==a[i])
		continue;
		else{
			b=a[j];
			a[j]=a[i];
			a[i]=b;
		}
	}
	}
	for(i=1;i<=num;i++)
	{
		cout<<a[i];
	}
}
