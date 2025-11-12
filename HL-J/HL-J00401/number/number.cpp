#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	char s[1000001];
	cin >> s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')num[int(s[i]-'0')]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++)cout << i;
	}
	return 0;
}
