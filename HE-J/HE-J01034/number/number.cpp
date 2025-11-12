#include<bits/stdc++.h>
using namespace std;
string a;
int num[11];
int main()
{
	freopen("number4.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>a;
	memset(num,0,sizeof(num));
	for(int i=0;i<a.size();i++) if(a[i]>='0'&&a[i]<='9') num[a[i]-'0']++;
	for(int i=9;i>=0;i--)
	{
		for(int j=num[i];j>=1;j--) cout<<i;
	}
	return 0;
}
