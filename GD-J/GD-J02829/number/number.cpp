#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,a[1000000+10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9') a[++T]=s[i]-'0';
	}
	sort(a+1,a+T+1);
	for(int i=T;i>=1;i--) cout<<a[i];
	return 0;
} 
