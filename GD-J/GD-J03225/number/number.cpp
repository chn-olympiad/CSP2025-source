#include<bits/stdc++.h>
using namespace std;
const int N=15;
int sl[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);cout.tie(0);
	string s;cin>>s;
	memset(sl,0,sizeof(sl));
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')sl[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sl[i];j++)cout<<i;
	}
	return 0;
}
