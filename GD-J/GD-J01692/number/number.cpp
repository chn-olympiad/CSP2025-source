#include <bits/stdc++.h>
using namespace std;
const int maxx=1e6+10;
string s;
int a[maxx],pos=0;
bool cmp(int m,int n){
	return m>n;	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])) a[++pos]=s[i]-48;	
	}
	sort(a+1,a+pos+1,cmp);
	for(int i=1;i<=pos;i++) cout<<a[i];
	return 0;
} 
