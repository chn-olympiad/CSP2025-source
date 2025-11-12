 #include<bits/stdc++.h>
using namespace std;
string s,t,u;
vector<long long> num;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int a=s[i]-'0';
			num.push_back(a);
		}
	}
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<num.size();i++)
	{
		cout<<num[i];
	}
	return 0;
} 