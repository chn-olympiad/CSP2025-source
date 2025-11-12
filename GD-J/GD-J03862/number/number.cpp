#include<bits/stdc++.h>
using namespace std;
string s;int n=0,l,c,a[1000010]={};
bool cmp(int pre,int nxt){
	return pre>nxt;
}
int main(){
  	freopen("number.in","r",stdin);
  	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c=s[i]-'0';
			a[c]++;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}
