#include<bits/stdc++.h>
#define ll long long
using namespace std;
string ss;
ll f[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> ss;
	for(int i=0;i<ss.size();i++) if(ss[i]>='0' && ss[i]<='9') f[int(ss[i]-'0')]++;
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=f[i];j++) cout << i;
	}
	
	return 0;
}
/*
Rp++
T1 too water~
*/

