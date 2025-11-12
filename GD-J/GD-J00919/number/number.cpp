#include<bits/stdc++.h>
using namespace std;
string qs,as;
char t;

int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>qs;
	for(int i=0;i<qs.size();i++)
	{
		if(qs[i]<='9'&&qs[i]>=0) as+=qs[i];
	}
	for(int i=0;i<as.size();i++)
	{
		for(int j=0;j<as.size()-i-1;j++)
		{
			if(as[j]<as[j+1])
			{
				t=as[j];
				as[j]=as[j+1];
				as[j+1]=t;
			}
		}
	}
	for(int i=0;i<as.size();i++)
	{
		cout<<as[i];
	}
	return 0;
} 
