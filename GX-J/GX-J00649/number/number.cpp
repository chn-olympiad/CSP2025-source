#include<bits/stdc++.h>
using namespace std;
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int main()
{

    string s,a;
    cin>>s;
    int n=s.size();	
    for(int i=1;i<=n;i++)
    {
		if(s[i]>s[i-1])
		{
			swap(s[i],s[i-1]);
		}
	}
	cout<<s;
    return 0;
}
