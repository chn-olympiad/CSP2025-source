#include<bits/stdc++.h>
using namespace std;
string s,r;
int ste(int x,int y)
{
    return x>y;
}
long long a[1000001],sb,ans,t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	sb=s.size();
	for(int i=0;i<=sb;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
            r[ans]=s[i];
            ans++;
			continue;
		}
	}
	for(int i=0;i<=ans;i++)
    {
        a[i]=int(r[i]);
    }
    sort(a,a+ans+1,ste);
    for(int i=0;i<=ans;i++)
    {
        cout<<char(a[i]);
    }
    return 0;
}

