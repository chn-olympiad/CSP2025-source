#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		a[i]=s[i];
		if(a[i]>=97)
			a[i]=-1;
		else
			a[i]-=48;
	}
    for(int i=0;i<s.size();i++)
    {
    	for(int j=i;j<s.size();j++)
        {
    	    if(a[j]>=a[i])
    	    	swap(a[i],a[j]);
    	}
	}
	for(int i=0;i<s.size();i++)
	{
		if(a[i]>=0)
			cout<<a[i];
		else
			break;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
