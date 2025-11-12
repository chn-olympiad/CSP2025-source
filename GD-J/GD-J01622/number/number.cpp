#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[s.size()]={0};long long k=0;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[k] = s[i]-'0';
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(long long i=0;i<k;i++)
	{
		cout<<a[i];
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
} 
