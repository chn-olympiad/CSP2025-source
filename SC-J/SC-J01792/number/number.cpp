#include<bits/stdc++.h>
using namespace std;
string a;
int cnt[12];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9')
			cnt[a[i]-'0']++;
	for(int i=9;i>=0;i--)
	{
		while(cnt[i]--) cout<<i;
	}
	return 0;
}
/*
T1正常发挥
这道题只需要将字符串中的数全部找出来，随后从大到小输出即可
 
*/ 