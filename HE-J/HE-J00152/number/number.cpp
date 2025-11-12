#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}int ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[cnt++]=s[i]-'0';
		}
	}
	sort(ans,ans+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<ans[i];
	}
	return 0;
}
