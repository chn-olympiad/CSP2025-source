#include<bits/stdc++.h>
using namespace std;
string s;
long long f[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	long long t=s.size();
	for(int i=0;i<t;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			f[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(f[i]!=0)
		{
			while(f[i]--)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
