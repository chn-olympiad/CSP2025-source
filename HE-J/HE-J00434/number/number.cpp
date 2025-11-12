#include<bits/stdc++.h>
using namespace std;
string s;
int i,n;
long long a[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	n=s.size();
	for(i=0;i<n;i++)
	    if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']+=1;
	for(i=9;i>=0;i--)
	{
		while(a[i]!=0)
		{
			cout<<i;
			a[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
