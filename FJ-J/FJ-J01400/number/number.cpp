#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
int t[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') t[++cnt]=int(s[i]-'0');
	}
	sort(t+1,t+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<t[i];
		if(t[i]==0&&i==cnt) break;
	}
	return 0;
}
