#include<bits/stdc++.h>
using namespace std;
string str;
int c[1000010];
int js=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,str);
	for(int i=0;i<str.size();i++)
	if(str[i]>='0'&&str[i]<='9')c[++js]=str[i]-'0';
	sort(c+1,c+js+1,cmp);
	for(int i=1;i<=js;i++)cout<<c[i];
	return 0;
} 
