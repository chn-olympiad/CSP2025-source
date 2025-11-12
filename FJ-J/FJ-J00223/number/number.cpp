#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b; 
}
int number[100005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
		
	string a;
	cin >> a;
	int l=a.size()-1,sum=0;
	for (int i=0;i<=l;i++)
	{
		if (a[i]<='9' && a[i]>='0')
		{
			number[i]=a[i]-48;
			//cout << a[i] << endl;
			sum++;
		}
	}
	sort(number,number+l+1,cmp);
	for (int i=0;i<sum;i++)
	{
		cout << number[i];
	}
	return 0;
}
