#include<bits/stdc++.h>
using namespace std;
string s;
int a[2000000],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k++;
			a[k]=(s[i]-'0');
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
