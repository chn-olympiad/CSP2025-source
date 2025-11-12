#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6+200;
int a[N];
bool cmp(int a,int b)
{
	return a > b; 
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false) ;
	cin.tie(0);
	string s;
	cin >> s;
	int i = 1;
	for(char g : s)
	{
		if(g >= '0' && g <= '9')
		{			
			a[i] = (g-'0');
 
			i++;
		}
	}
	sort(a+1,a+i,cmp);
	for(int j = 1; j < i ; j ++)
	{
		cout<<a[j];
	}
	return 0;
}