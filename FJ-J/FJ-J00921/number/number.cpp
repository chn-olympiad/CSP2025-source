#include<bits/stdc++.h>
using namespace std;
int a[1000010],len=0;
string c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int n=c.size();
	for(int i=0;i<n;i++)if('0'<=c[i]&&c[i]<='9')a[++len]=c[i]-'0';
	sort(a+1,a+1+len);
	for(int i=len;i>=1;i--)cout<<a[i];
	return 0;
}
