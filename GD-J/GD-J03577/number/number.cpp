#include<bits/stdc++.h>
using namespace std;
int a[20],len;
char s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=strlen(s);
	for(int i=1;i<=len;i++){
		int x=s[i]-'0';
		if(x>=0&&x<=9) a[x]++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
