#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
char s[N];

int n;

bool cmp(char x,char y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(n=0;s[n]>='a'&&s[n]<='z'||s[n]>='0'&&s[n]<='9';n++);
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++){
		if(s[i]>='a'&&s[i]<='z') continue;
		cout<<s[i];
	}
	
	return 0;
}
