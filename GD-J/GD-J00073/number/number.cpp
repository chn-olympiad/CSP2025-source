#include<bits/stdc++.h> 
using namespace std;
char s[1000005];
int m[10005],x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>s;
	for(int i=0;i<sizeof(s);i++){
		if('0'<=s[i]&&s[i]<='9'){
			m[x]=s[i]-'0';
			x++;
		} 
	} 
	sort(m,m+x,cmp);
	for(int i=0;i<x;i++)cout<<m[i];
	return 0;
}
