#include<bits/stdc++.h>
using namespace std;
string s;
char n[1000005];
int t=1;
bool cmp(char a,char b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[t]=s[i];
			t++;
		}
	}
	sort(n+1,n+t,cmp);
	for(int i=1;i<t;i++)cout<<n[i];
	return 0;
}
