#include <bits/stdc++.h>
using namespace std;
int a=0;
char s[1000010];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	while(s[a]!=0){
		a+=1;
	}
	for(int i=1;i<=a;i++){
		if(s[i]>'9'){
			s[i]=' ';
			//cout<<s[i];
		}
	}
	sort(s,s+a,cmp);
	cout<<s;
	return 0;
}

