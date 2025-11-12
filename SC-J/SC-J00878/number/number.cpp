#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mx=1e6+10;
int a[mx],cnt;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++cnt]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--)cout<<a[i];
}