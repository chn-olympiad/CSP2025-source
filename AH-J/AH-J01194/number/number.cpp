#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int ans[N];
int cnt;
string s;
int len;
bool isnum(char ch);
bool cmp(const int a,const int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for (int i=0;i<len;i++){
		if (isnum(s[i])){
			cnt++;
			ans[cnt]=s[i]-'0';
		}
	}
	sort(ans+1,ans+1+cnt,cmp);
	for (int i=1;i<=cnt;i++){
		cout<<ans[i];
	}
	return 0;
}
bool isnum(char ch){
	if (ch>='0'&&ch<='9')return true;
	return false;
}
