#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long k=0;
	long long p=0;
 	long long l=s.size();
	for(long long i=0;i<l;i++)
	{
		if(s[i]=='0'|| s[i]=='1'|| s[i]=='2'|| s[i]=='3'||
		s[i]=='4'|| s[i]=='5'|| s[i]=='6'|| s[i]=='7'||
		s[i]=='8'|| s[i]=='9')
		{
			p++;
		} 
	}
	vector<char> a(p);
	for(long long i=0;i<l;i++)
	{
		if(s[i]=='0'|| s[i]=='1'|| s[i]=='2'|| s[i]=='3'||
		s[i]=='4'|| s[i]=='5'|| s[i]=='6'|| s[i]=='7'||
		s[i]=='8'|| s[i]=='9')
		{
			a[k]=s[i];
			k++;	
		} 
	}
	sort(a.begin(),a.end());
	for(long long j=k-1;j>=0;j--)
	{
		cout<<a[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
