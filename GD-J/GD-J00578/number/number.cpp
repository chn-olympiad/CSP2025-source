#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1000010];
bool cmp(int xx,int yy)
{
	return xx > yy;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.length(),key = 1;
	for(int i = 0;i < len;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			arr[key] = s[i] - '0';
			key++;
		}
	}
	sort(arr + 1,arr + key,cmp);
	for(int i = 1;i < key;i++)
	{
		cout << arr[i];
	}
	cout << endl;
	return 0;
 } 

