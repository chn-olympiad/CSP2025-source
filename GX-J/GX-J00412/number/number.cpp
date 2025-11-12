#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long int a[1000011];
	int cnt=0;
	int sl=0;
	char b;
	cin>>s;
	sl=s.size();
	for(int i=0;i<sl;i++)
	{
		if(s[i]<='9')
		{
		    b=s[i];
			a[++cnt]=b;
			a[cnt]=a[cnt]-48;
		}
	}
    sort(a+1,a+1+cnt);
    for(int i=cnt;i>0;i--)
    {
        cout<<a[i];
    }
    return 0;
}
