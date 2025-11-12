#include<bits/stdc++.h>
using namespace std;
char s;
char s1[10000005];
int x=1;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&s)&&s!='\n'){
		if(s>='0'&&s<='9'){
			s1[x]=s;
			x++;
		}
	}
	x--;
	sort(s1+1,s1+x+1,cmp);
	for(int i=1;i<=x;i++){
		cout<<s1[i];
	}
	return 0;
}