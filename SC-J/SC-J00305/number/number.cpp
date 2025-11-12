#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s;
int a[N];
int main()
{
	int j=1;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
	{
		if(s>='0'&&s<='9')
		{
			a[j]=s-'0';
			j++;
		}
	}
	sort(a+1,a+1+j);
	for(int i=j;i>1;i--)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}