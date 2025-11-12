#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a[N];
char cmp(char a,char b){
	return a>b;
}
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[i]=s[i];
		}
	}
	sort(a,a+len,cmp);
	for(int i=0;i<len;i++){
		cout<<a[i];
	}
	
	return 0;
}

