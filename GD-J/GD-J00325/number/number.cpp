#include<bits/stdc++.h>
#define int long long
#define mod 998344353
using namespace std;
string s;
int num[1000005],cur=0;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')num[++cur]=s[i]-'0';
	}
	sort(num+1,num+1+cur,cmp);
	for(int i=1;i<=cur;i++){
		cout<<num[i];
	}
	return 0;
}
