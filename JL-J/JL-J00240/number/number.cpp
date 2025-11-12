#include<bits/stdc++.h>
using namespace std;
char s[1000100];
long long l=1,a[1000100],c;
bool cmp(int a,int b){
	if(a>b)return 1;
	else return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=int(strlen(s));i++){
		if(isdigit(s[i])){
			a[i]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+strlen(s)+1,cmp);
	for(int i=0;i<c;i++){
		cout<<a[i];
	}
	return 0;
}
