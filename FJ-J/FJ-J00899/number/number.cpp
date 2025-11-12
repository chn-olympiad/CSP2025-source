#include<bits/stdc++.h>
using namespace std;
int a[1000050],tt=0;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[++tt]=s[i]-48;
		}
	}
	sort(a+1,a+tt+1,cmp);
	for(int i=1;i<=tt;i++){
		cout<<a[i];
	}
	return 0;
}