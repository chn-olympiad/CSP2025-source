#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int q[1000010],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			q[++top]=s[i]-'0';
		}
	}
	sort(q+1,q+top+1);
	for(int i=top;i>=1;i--){
		printf("%d",q[i]);
	}
	return 0;
}
