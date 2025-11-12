#include <bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
int l;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	//cout<<s<<endl;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		//cout<<s[i]<<endl;
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			a[cnt]=s[i]-'0';
			//cout<<a[cnt];
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
}
