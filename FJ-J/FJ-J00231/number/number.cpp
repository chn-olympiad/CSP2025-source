#include<bits/stdc++.h>
using namespace std;
string s,ans;
char num[1000005];
int cnt;
bool cmp(char a,char b){
	return a-'0'>b-'0';
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.length();i++){
		if (!(s[i]>=97&&s[i]<=122)&&!(s[i]>=65&&s[i]<=90)){
			num[++cnt]=s[i];
		}
	}
	sort(num+1,num+1+cnt,cmp);
	for (int i=1;i<=cnt;i++){
		ans+=num[i];
	}
	cout<<ans;
	return 0;
}
