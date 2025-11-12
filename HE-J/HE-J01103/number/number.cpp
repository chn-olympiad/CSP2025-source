#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],op;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			op++;a[op]=s[i]-'0';
		}
	}sort(a+1,a+op+1);
	for(int i=op;i>=1;i--)cout << a[i];
	return 0;
} 
