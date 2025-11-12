#include<bits/stdc++.h>
using namespace std;
int num[10000];
string s;
void maxed(){
	int l=s.length();
	for(int i=0;i<l;i++)if(48<=int(s[i])&&int(s[i])<=57)num[int(s[i])-48]++;
	bool flag=true;
	for(int i=1;i<=9;i++)if(num[i])flag=false;
	if(flag){
		printf("0");
		return ;
	}
	for(int i=9;i>=0;i--)for(int j=0;j<num[i];j++)printf("%d",i);
	return ;
}
int main(){
	freopen("number4.in","r",stdin);
	freopen("number4.ans","w",stdout);
	cin>>s;
	maxed();
	return 0;
}
