#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
bool cmp(int c,int b){
	return c>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0,ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='1'&&s[i]<='9')a[i]=(s[i]-'0'),cnt++;
		else if(s[i]=='0')a[i]=-1,ans++;
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<cnt;i++){
		if(a[i]!=0)cout<<a[i];
	}
	for(int i=1;i<=ans;i++)cout<<0;
	return 0;
}
