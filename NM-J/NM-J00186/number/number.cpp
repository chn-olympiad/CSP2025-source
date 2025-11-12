#include<bits/stdc++.h>
using namespace std;
long long int a[10000000];
bool cmd(long long int c,long long int d){
	return c>d;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long int b=0;
	for(long long int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=int(s[i]-'0');
			b++;
		}
	}
	sort(a,a+b,cmd);
	for(long long int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;
} 
