#include<bits/stdc++.h>
using namespace std;
string s,ans;
vector<int> v; 
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++)//±éÀú×Ö·û´® 
	{
		if(s[i]>='0'&&s[i]<='9')//ÊÇÊý×Ö 
		{
			v.push_back(s[i]-'0');
		} 
	}
	sort(v.begin(),v.end());//ÅÅÐòÕÒ×î´ó 
//	for (int i=0;i<v.size();i++)
//	{
//		cout<<v[i]<<" "; 
//	}
	for (int i=v.size()-1;i>=0;i--)
	{
		ans+=v[i]+48;
	} 
	cout<<ans;
	return 0;
}
