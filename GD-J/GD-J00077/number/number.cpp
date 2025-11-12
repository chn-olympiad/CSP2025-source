#include<bits/stdc++.h>
using namespace std;
const int N=10e6+5;
char s[N];
int num[N],x;
bool cmp(int a,int b){
	return b<a;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[x]=s[i]-48;
			x++;
		}
	}
	sort(num,num+x,cmp);
	for(int i=0;i<x;i++){
		cout<<num[i];
	} 
	return 0;	
} 
