#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,b;
	int a[10000];
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			a[++k]=int(s[i]);
		}
	}
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--)
	{
		b+=char(a[i]);
	}
	cout<<b<<endl;
	fclose(stdin);
    fclose(stdout);
	return 0;
} 
