#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
	}
string s;
string a;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(long long i=0;i<s.size();i++)
if(s[i]>='0'&&s[i]<='9')a.push_back(s[i]);	
sort(a.begin(),a.end(),cmp);
for(auto c:a)
cout<<c;
return 0;
}
