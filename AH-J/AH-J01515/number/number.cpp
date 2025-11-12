#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++t]=s[i]-'0';
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++)
		cout<<a[i];
	return 0;
}
