#include<bits/stdc++.h>
using namespace std;
string a;
int num[10];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
 	cin >> a;
 	for(int i = 0;i<a.length();i++)
 	{
 		if(int(a[i])-int('0')>=0&&int(a[i])-int('0')<=9)
 		num[int(a[i])-int('0')]++;
 	}
 	for(int i = 9;i>=0;i--)
	 {
	 	for(int j = 1;j<=num[i];j++)
	 	cout << i;
	 }
	return 0;
}

