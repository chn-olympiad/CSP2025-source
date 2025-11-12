#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a=s.length();
    int f[10005]={0},an=0;
    for(int i=0;i<a;i++)
    {
		if(s[i]>='0'&&s[i]<='9')
		{
			f[an]=s[i]-48;
			an++;
		}
	}
	sort(f,f+an);
	for(int i=an-1;i!=0-1;i--)cout<<f[i];
    return 0;
}
