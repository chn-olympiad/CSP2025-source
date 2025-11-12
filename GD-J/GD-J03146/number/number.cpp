#include<bits/stdc++.h>
using namespace std;

string s;
int a[10];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>s;
	for(auto c : s) if(isdigit(c)) a[c-'0']++;
	for(int i=9;i>=0;i--) while(a[i]--) cout<<i;
	return 0;
}
