#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]--)cout<<i;
	return 0;
}
