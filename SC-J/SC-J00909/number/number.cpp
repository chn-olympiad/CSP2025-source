#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[1000010],cnt;
char ch;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	while(cin>>ch){
		if('0'<=ch&&ch<='9')num[++cnt]=ch-'0';
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<num[i];
}