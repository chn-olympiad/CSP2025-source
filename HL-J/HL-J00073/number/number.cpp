#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000009],s1[1000009];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			s1[i]=s[i];
		}
	}
	sort(s1+0,s1+l,cmp);
	cout<<s1;
	return 0;
}
