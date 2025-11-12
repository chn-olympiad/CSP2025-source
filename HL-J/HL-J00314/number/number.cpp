#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s;
char a[5000010];
int tot=0;
bool cmp(int a,int b){
	return a>b;
}
bool isnum(int i){
	if(s[i]>='0'&&s[i]<='9') return true;
	else return false;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isnum(i)) a[++tot]=s[i];
	}
	sort(a+1,a+1+s.size(),cmp);
	for(int i=1;i<=tot;i++){
		cout<<a[i];
	}
	return 0;
}
