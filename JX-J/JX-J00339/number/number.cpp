#include<bits/stdc++.h>
using namespace std;
char t[1000005];
int s[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",t);
	int j=0;
	int h=strlen(t);
	for(int i=0;i<h;i++){
		if(t[i]>='0'&&t[i]<='9'){
		s[j++]=t[i]-'0';
		}
	}
sort(s,s+j);
	for(int i=j-1;i>=0;i--){
	printf("%d",s[i]);
	}
return 0;
}
