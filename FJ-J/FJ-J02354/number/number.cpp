#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+100;
string s;
int a[N],t;
bool cmp(int b,int c){
	return b>c;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++) cout<<a[i];
	return 0;
}
