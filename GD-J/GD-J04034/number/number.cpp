#include<bits/stdc++.h>
using namespace std;
string str;
int a[1000010],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int l=str.size();
	for(int i=0;i<l;i++)
	{
		if('0'<=str[i]&&'9'>=str[i])
		{
			n++;
			a[n]=int(str[i]-'0');
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
		cout<<a[i];
	return 0;
}
