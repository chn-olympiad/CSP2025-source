#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],t=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')a[t]=(s[i]-'0'),t++;
	sort(a+1,a+t,cmp);
	for(int i=1;i<t;i++)cout<<a[i];
	return 0;
}
