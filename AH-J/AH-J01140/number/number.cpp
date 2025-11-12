#include<bits/stdc++.h>
using namespace std;

string s;
char a[1000005];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t = 1;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] <= '9' && s[i] >= '0'){
			a[t] = s[i];
			t++;
		}
	}
	sort(a + 1, a + t);
	for(int i = t - 1; i >= 1; i--) cout<<a[i];
	return 0;
}
