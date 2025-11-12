#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
char s[1000010];
unsigned int numberCount[11];
bool isOnlyZero=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	unsigned int sLength=strlen(s);
	for(int i=0;i<sLength;i++)if(isdigit(s[i]))numberCount[s[i]-'0']++;
	short p=9;
	while(p>0){
		if(!isOnlyZero)isOnlyZero+=numberCount[p];
		while(numberCount[p]){
			cout<<p;
			numberCount[p]--;
		}
		p--;
	}
	if(!isOnlyZero){
		cout<<0;
	}else{
		while(numberCount[0]){
			cout<<0;
			numberCount[0]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
