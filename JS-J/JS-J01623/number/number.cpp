#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int cnt[150];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
		if('0'<=a[i] and a[i]<='9') cnt[a[i]]++;
	for(char i='9';i>='0';i--)
		while(cnt[i]>0) cout<<i,cnt[i]--;
	return 0;
}
