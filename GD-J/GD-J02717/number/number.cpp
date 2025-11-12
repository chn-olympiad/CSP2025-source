#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int i,len=s.size(),k=0;
	for(i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++k]=s[i]-'0';
	sort(a+1,a+k+1);
	for(i=k;i>=1;i--) cout<<a[i];
	return 0;
}
