#include<bits/stdc++.h>
using namespace std;
string s;
int j=1;
int a[1000000];
int main()
{
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>s;
	int q=s.length();
	for(int i=0;i<q;i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	for(int k=0;k<j-1;k++){
		for(int i=0;i<j-1;i++)
		{
			if(a[i]<a[i+1])
			{
				int cc=a[i];
				a[i]=a[i+1];
				a[i+1]=cc;
			}
		}
	}
	for(int i=0;i<j-1;i++){
	cout<<a[i];}
	return 0;
}
