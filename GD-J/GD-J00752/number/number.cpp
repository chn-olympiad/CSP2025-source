#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[135];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto p:s) cnt[p]++;
	for(int i='9';i>='0';i--)
		while(cnt[i]--) putchar(i);
	return 0;
}
