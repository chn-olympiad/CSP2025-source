#include<bits/stdc++.h>
using namespace std;
string s;
long long a[105],w;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]]++;
		}
    }
	for(int i=57;i>=48;i--)
	{
		if(a[i]!=0)
		{
			for(int j=a[i];j>0;j--)
			{
				cout<<i-48;
			}
		}
	}

	return 0;
}

