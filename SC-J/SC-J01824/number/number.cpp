#include<bits/stdc++.h>
using namespace std;
int a[1000000],t;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t++]=int(s[i])-48;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++)cout<<a[i];
	return 0;
}