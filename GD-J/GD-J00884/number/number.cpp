#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s;
int t,a[2000008];
int cmp(int a,int b){
	return a>b;
}
main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0'; 
	}
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++) cout<<a[i];
	return 0;
}
