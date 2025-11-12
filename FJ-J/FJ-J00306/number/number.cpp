#include<bits/stdc++.h>
using namespace std;
string s;
int f[1000005],t=0;
bool c(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			f[t]=(int)s[i]-48;
			t++;
		}
	}
	sort(f,f+t,c);
	for (int i=0;i<t;i++){
		cout<<f[i];
	}
	return 0;
}
