#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],w;
int main(){
	//*freopen("number.in","r",stdin);
	//*freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.size();
	for(int i=0;i<l;i++)
	{
		if(int(s[i])>=48&&int(s[i])<=57)
		{
			a[w]=int(s[i])-48;
			w++;
		}
	}
	sort(a,a+w);
	for(int i=w-1;i>=0;i--)
	{
		cout<<a[i];
	}
}
