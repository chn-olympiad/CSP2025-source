#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ans[10]={},i=0;
	string st;
	cin>>st;
	while(i<(st.length()))
	{
		if('0'<=st[i]&&'9'>=st[i])ans[st[i]-'0']++;
		i++;
	}
	for(i=9;i>=0;--i)
		while(ans[i])
		{
			cout<<i;
			ans[i]--;
		}
	cout<<endl;
	return 0;
	
}
