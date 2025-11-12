#include<bits/stdc++.h>
using namespace std;
char s[1000100];
long long num[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')
		num[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(num[i]>0){
			cout<<i;
			num[i]--;
		}
	}
	return 0;
}
