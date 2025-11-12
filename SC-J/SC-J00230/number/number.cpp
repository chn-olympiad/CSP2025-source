#include<bits/stdc++.h>
using namespace std;

string str;
int num[1145141], cnt;

bool cmp(int a, int b){
	return a>b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
		if(str[i]-'0'>=0&&str[i]-'0'<=9)
			num[++cnt]=str[i]-'0';
	sort(num+1, num+1+cnt, cmp);
	for(int i=1;i<=cnt;i++)
		cout<<num[i];
	return 0;
}