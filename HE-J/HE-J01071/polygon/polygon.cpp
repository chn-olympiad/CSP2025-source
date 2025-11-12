#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in""v""stdin")
	freopen("polygon.out""w""stdin")
	string s;
	int cnt=0;
	cin>>s;
	for(int l=1;l<=s.size();l++)
	{
	    for(int i=1;i<=s.size();i++)
	    {
		    if(s[i]<=s[i-1])
		    {
			swap(s[i],s[i-1]);
			cnt++;
	    	}
	    	if(cnt==s.size())
	    	{
	    		cout<<s[i];
			}
	    }
    }
	return 0;
}
