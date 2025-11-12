#include<bits/stdc++.h>
using namespace std;
string s;
int a[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,i,j;
	getline(cin,s);
	n=s.size();
	for(i=0;i<n;i++)
		if(s[i]>='0' && s[i]<='9') a[s[i]-'0']++;
	for(i=9;i>=0;i--)
	    if(a[i]!=0)
	    {
	    	for(j=1;j<=a[i];j++)
	    	    cout<<i;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
