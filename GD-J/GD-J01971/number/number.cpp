#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')
			a.push_back(s[i]-'0');
	sort(a.begin(),a.end(),[](int x,int y)
	{
		return x>y;
	});
	for(auto i:a)
		printf("%d",i);
	return 0;
}
