#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
	}
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++) cout<<a[i];
	return 0;
}
