#include<bits/stdc++.h>
using namespace std;
char s[1000009];
vector<char> v;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)if(isdigit(s[i]))num[s[i]-'0']++;
	for(int i=9;i>=0;i--)while(num[i]--)printf("%d",i);
}