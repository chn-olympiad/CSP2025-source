#include<bits/stdc++.h>
using namespace std;
string s;
char c1;
int ci=1;
char c[1000005];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		c1=s[i];
		if(c1>=48&&c1<=57){
			c[ci]=c1;
			ci++;
		}
	}
	sort(c+1,c+ci,cmp);
	for(int i=1;i<=ci-1;i++){
		printf("%c",c[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}