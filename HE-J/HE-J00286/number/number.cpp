#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e6+10;
char s[MAXN];
int cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			int num=s[i]-'0';
			cnt[num]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		} 
	}
	return 0;
} 
