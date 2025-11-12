#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int num[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
