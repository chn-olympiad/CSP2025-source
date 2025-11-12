#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;
	for(char&c:s)if(isdigit(c))++a[c-'0'];
	for(int i=9;~i;--i)cout<<string(a[i],i+'0');
}