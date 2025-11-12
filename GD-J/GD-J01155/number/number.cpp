#include<iostream>
#include<cstdio>
using namespace std;
string s;
int a[10],maxn;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			maxn=max(maxn,s[i]-'0');
		}
	}
	if(maxn=0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
} 
