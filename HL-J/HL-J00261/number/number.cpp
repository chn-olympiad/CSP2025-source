#include<bits/stdc++.h>
using namespace std;
const int F=1100000;
char s[F];
int k[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			k[s[i]-'0']++;
			//cout<<'c';
		}
	}
	for(int i=9;i>=0;i--){
		while(k[i]>0){
			k[i]--;
			cout<<i;
		}
	}
}
