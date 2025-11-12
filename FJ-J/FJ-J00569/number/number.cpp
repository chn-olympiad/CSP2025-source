#include<bits/stdc++.h>
#define L 1000010
using namespace std;
string s="";
int a[L];
int cmd=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[cmd++]=s[i]-48;
		}
	}
	sort(a,a+cmd,cmp);
	for(int i=0;i<cmd;i++){
		cout<<a[i];
	}
	return 0;
}
