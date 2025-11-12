#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],t;
bool check(){
	for(int i=1;i<t;i++){
		if(a[i]>a[i+1]) return 1;
	}
	return 0;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++t]=s[i]-'0';
		}
	}
	if(check()) sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
} 
