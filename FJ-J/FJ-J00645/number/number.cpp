#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
string n;
int m[maxn];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>n;
	for(int i =0;i<n.size();i++)
	{
		if(n[i] <= '9' && n[i] >= '0')
			m[(int)(n[i] - '0')]++;
	}
	for(int i =9;i>=0;i--)
	{
		for(;m[i]>0;m[i]--)
		{
			cout << i;
		}
	}
	
	return 0;
}
