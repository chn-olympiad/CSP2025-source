#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
    long long l=s.length();
	long long k=1;
	for(int i=0;i<=l;i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=(s[i]-'0');
			k++;
		}
	}
	sort(a+1,a+k+1);
	for(long long i=k;i>1;i--)
	{
		cout<<a[i];
	} 
	return 0;
}