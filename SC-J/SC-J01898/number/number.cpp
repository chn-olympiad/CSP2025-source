#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1000;
string s;
int i,a[N],c=0;
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.length();i++)
		if(isdigit(s[i])){
			a[c]=s[i]-'0';
			c++;
		}
	sort(a,a+c,cmp);
	for(i=0;i<c;i++)cout<<a[i];
	return 0;
}