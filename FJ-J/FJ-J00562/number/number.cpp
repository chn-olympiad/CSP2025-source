#include <bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=int(s.size()),al=int(s.size());
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9') a[i+1]=s[i]-'0';
		else al--;
	}
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=al;i++) cout<<a[i];
	return 0;
}
