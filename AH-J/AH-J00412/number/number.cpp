#include<bits/stdc++.h>
using namespace std;
char ch;
long long f[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>ch){
		if(ch>='0'&&ch<='9')f[ch-'0']++;
	}
	for(long long i=9;i>=0;i--){
		while(f[i]--)cout<<i;
	}
	return 0;
}
