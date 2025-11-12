#include<bits/stdc++.h>
using namespace std;
string s,ans;
int a[10];
char b[10]={'0','1','2','3','4','5','6','7','8','9'};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if('0'<=s[i] && s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)ans+=b[i];
	}
	cout<<ans;
	return 0;
}
