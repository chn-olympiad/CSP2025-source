#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std; 
char s[1000010];
int n,cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]){
			putchar(i+'0');
			cnt[i]--;
		}
	}
	return 0;
}
