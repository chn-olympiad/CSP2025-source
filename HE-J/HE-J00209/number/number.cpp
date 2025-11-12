#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int idx=0;
int main(){
//	freopen("number4.in","r",stdin);
//	freopen("number4.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])) a[++idx]=s[i]-'0';
	}
	sort(a+1,a+idx+1,cmp);
	for(int i=1;i<=idx;i++) cout<<a[i];
	return 0;
}
