#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>=0&&a[i]<=9)
		{
			cout<<5;
			break;
		}
	}
    return 0;	
}
