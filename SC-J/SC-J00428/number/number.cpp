#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s;
int a[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.ont","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(a,0,sizeof(a));
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0'+1]++;
	}
	for(int i=10;i>=1;i--){
		for(int j=1;j<=a[i];j++) cout<<i-1;
	}
	return 0;
}