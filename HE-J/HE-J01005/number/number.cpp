#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],top=0;
string s;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9') a[++top]=s[i]-'0';
	}
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=top;i++) cout<<a[i];
	return 0;
}

