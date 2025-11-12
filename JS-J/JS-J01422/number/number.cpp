#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char i:s)if(isdigit(i))++cnt[i-'0'];
	for(int i=9;~i;i--)while(cnt[i]--)putchar(i+'0');
	return 0;
}
