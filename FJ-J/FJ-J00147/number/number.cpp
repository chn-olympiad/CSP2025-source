#include<bits/stdc++.h>
using namespace std;
int n[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int alen=a.size();
	for(int i=0;i<alen;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			n[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=n[i]-1;j>=0;j--)
		{
			cout<<i;
		}
	}
	return 0;
}
