#include<bits/stdc++.h>
using namespace std;
int b[1000005];
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int q=1;
	cin>>s;
	for(int i=0;(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9');i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[q++]=s[i]-48;
		}
	}
	sort(b+1,b+q,cmp);
	for(int i=1;i<=q-1;i++){
		cout<<b[i];
	}
	return 0;
}
