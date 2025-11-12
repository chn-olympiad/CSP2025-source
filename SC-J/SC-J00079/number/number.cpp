#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length()-1;
	for(int i=0;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	int flag=0;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) printf("%lld",i);
	}
	return 0;
}
//while(1) rp++;
//Let me fly again