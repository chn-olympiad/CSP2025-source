#include<bits/stdc++.h>
using namespace std;



int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k!=1)
		for(int i=1;i<=k;i++)
			cout<<0<<endl;
	else
	{
		string s1,s2;
		int ans;
		cin>>s1>>s2;
		for(int i=1;i<=s1.length();i++)
		{
			if(s1[i]!=s2[i])
			ans++;
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
