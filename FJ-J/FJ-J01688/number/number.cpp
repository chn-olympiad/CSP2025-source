#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _sg string
ll rd(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
_sg s;
_sg t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')
		t[s[i]-'0']+=s[i];
	}
	for(int i=9;i>=0;i--){
		cout<<t[i];
	}
	return 0;
}
