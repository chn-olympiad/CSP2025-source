#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
	return a>b;
}
string b[1000002];
int num=1;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.ouy","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.ouy","w",stdout); 
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[num]=a[i];
			num++;
		}
	}
	string ans;
	sort(b+1,b+num+1,cmp);
	for(int i=1;i<=num;i++)
	{
		ans+=b[i];
	}
	cout<<ans;
	return 0;
 } 
