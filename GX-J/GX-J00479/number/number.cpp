#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int f(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=s.size(),ans=0;
	int j=0;
	for(int i=0;i<cnt;i++){
			if(s[i]>='1' && s[i]<='9'){
				a[j++]=s[i];
			}
			if(s[i]=='0') ans++;
	}
	sort(a,a+j,f);
	for(int i=0;i<j;i++){
			cout<<a[i];
	}
	while(ans--) cout<<0;
	return 0;
}
