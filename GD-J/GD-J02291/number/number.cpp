#include<iostream>
#include<map>
using namespace std;
int o[10]={0,0,0,0,0,0,0,0,0,0};
string s;
map<int,int>a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[s[i]-'0']++;
			o[s[i]-'0']=1;
		}
	} 
	for(int i=9;i>=1;i--)
	{
		if(o[i]==0) continue;
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}
