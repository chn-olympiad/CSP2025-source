#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
string a,b;
int s[N],j=0;
int main()
{
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if((a[i]-'0')>=0&&(a[i]-'0')<=9)
		{
        s[j]=(a[i]-'0');
        j++;
	    }
	}
	sort(s,s+j);
	j--;
    for(j;j>=0;j--) cout<<s[j];
	return 0;
} 
