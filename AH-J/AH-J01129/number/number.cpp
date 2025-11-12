#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,i=1;
int a[15];
char s[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>s[i])
	{
		if(s[i]>='0'&&s[i]<='9')
		{
		   int tmp=s[i]-'0';
		   a[tmp]++;
		}
		i++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
