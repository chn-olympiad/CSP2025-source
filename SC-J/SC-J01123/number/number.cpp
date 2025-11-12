#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],top=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++top]=s[i]-'0';
		}
	}
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=top;i++){
		cout<<a[i];
	}
	return 0;
}
/*
提出数字排序输出 
*/