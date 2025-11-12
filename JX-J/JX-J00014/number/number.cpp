#include<bits/stdc++.h>
using namespace std;
string s;
int len,len2,n[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number1.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9' && s[i]>='0'){
			n[++len2]=s[i]-'0';
		}
	}
	sort(n+1,n+len2+1,cmp);
	for(int i=1;i<=len2;i++){
		cout<<n[i];
	}
	return 0;
}
