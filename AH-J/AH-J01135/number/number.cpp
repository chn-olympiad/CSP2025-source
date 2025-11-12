#include<bits/stdc++.h>
using namespace std;
string s,t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	int l=s.size();
	for(int i=0;i<=l-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t=s[i]+t;
		}
		else
		{
			break;
		}
		//cout<<s[i]<<" "<<t<<" ";
	}
	while(t[0]=='0'&&t.size()>1)
	{
		t.erase(0,1);
	}
	cout<<t;
	return 0;
}
