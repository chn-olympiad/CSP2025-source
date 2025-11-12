#include<bits/stdc++.h>
using namespace std;
int f[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') f[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--) while(f[i]>0) putchar(i+'0'),f[i]--;
	return 0;
}