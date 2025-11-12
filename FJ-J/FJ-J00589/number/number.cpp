#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=s.length();
	int u=0;
	for(int i=0;i<k;i++)
	{
		char ch=s[i];
		if(ch>='0' && ch<='9')
		{
			a[u]=ch-'0';
			u++;
		}
		
	}
	sort(a,a+u);
	for(int i=u-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
