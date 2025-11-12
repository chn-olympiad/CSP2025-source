#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll a[1005],n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
		if(str[i]>='0'&&str[i]<='9')
			a[++n]=str[i]-'0';
	sort(a+1,a+n+1);
	if(a[n]==0)
    {
        cout<<0;
        exit(0);
    }
	for(int i=n;i>=1;i--)
		cout<<a[i];
	return 0;
}
