#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(!isdigit(s[i])) continue;
		else               a[++n]=s[i]-'0';
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) printf("%d",a[i]);
	return 0;
}

