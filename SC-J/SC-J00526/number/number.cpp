#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int j=a.size();
	int s[j];
	j=0;
	for(int i=0;i<a.size();i++)
	{
		s[i]=0;
		if(a[i]>='0'&&a[i]<='9') {
			s[j]=a[i]-'0';
			j++;
		}
	}
	int max=0,sum=0,w=0;
	for(int i=0;i<j;i++)
	{
		max=0,w=0;
		for(int k=0;k<j;k++)
		{
			if(s[k]>max) {
			max=s[k];w=k;}
		}
		cout<<max;
		s[w]=-1;
	}
	return 0;
 } 