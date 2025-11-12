#include <bits/stdc++.h>
using namespace std;
int a[100005]={99};
bool cmp(int a,int b)
{
	return b<a;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int cnt=0;
	for (int i = 0;i<=n.size();i++)
	{
		if (n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9'||n[i]=='0')
		{
			a[cnt] = n[i];
			a[cnt] = a[cnt]-48;
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for (int i = 0;i<cnt;i++)
	{
		if (a[i]!=99)
		{
			cout << a[i];
		}	
	}
	return 0;
} 
