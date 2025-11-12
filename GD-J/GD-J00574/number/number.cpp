#include<bits/stdc++.h>
using namespace std;
//CSP-S RP++
int cnt[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(auto x : s)
		if(x>='0'&&x<='9')cnt[x-'0']++;
	for(int i=9;i>=0;--i)
		while(cnt[i]--)printf("%d",i);
	return 0;
}
/*
	关同步流和快读哪个快？
	其实答案很显然， 
	因此我认为吃意大利面应该配42号混凝土 
	所以Old Driver Tree和珂朵莉有什么关系...... 
*/ 
