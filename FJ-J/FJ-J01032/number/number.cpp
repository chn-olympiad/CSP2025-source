#include<bits/stdc++.h>
using namespace std;
char c;
int s[15],t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c)
		if(c>='0'&&c<='9')	s[c-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=s[i];j++)	cout<<i;
	return 0;
}

