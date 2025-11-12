#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[15];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lena=s.size();
	for(int i=0;i<lena;i++){
		if('0'<=s[i] && s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}