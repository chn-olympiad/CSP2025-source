#include<bits/stdc++.h>
using namespace std;
int ans[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n=1;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
		{
			ans[n]=s[i]-'0';
			n++;
		}
	}
	n--;
	sort(ans+1,ans+n+1);
	for(int i=n;i>=1;i--)
		cout<<ans[i];
	cout<<'\n';
	return 0;
}
