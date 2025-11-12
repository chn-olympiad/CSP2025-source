#include<bits/stdc++.h>
using namespace std;
int c,a[1000006];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]<='9'&&s[i]>='0') a[++c]=s[i]-'0';
	sort(a+1,a+1+c,cmp);
	for(int i=1;i<=c;i++) cout<<a[i];
	return 0;
}