#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string s;
int l;
int a[2100000];
bool cmp(int a,int b){
	return a>b;
}
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++){
		cout<<a[i];
	}
	return 0;
}
