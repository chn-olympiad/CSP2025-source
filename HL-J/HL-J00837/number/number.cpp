#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int cnt=0;
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string x;
	cin>>x;
	int l=x.size();
	for(int i=0;i<l;i++)
	{
		if(x[i]>='0'&&x[i]<='9')
		{
			cnt++;
			a[cnt]=x[i];
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
