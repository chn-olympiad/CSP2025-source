#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s;
int a[1000000+5];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>s;
	int cnt;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt] = s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i = 1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
