#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
string s;
int a[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}