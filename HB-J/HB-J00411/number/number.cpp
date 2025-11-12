#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000009],cnt=0;
bool tmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[cnt++]=s[i]-'0';
		}
	}
	sort(num,num+cnt+1,tmp);
	for(int i=0;i<cnt;i++){
		printf("%d",num[i]);
	}
	printf("\n");
	return 0;
}
