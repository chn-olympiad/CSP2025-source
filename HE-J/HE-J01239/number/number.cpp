#include<bits/stdc++.h>
using namespace std;
long long a[102400];
int self(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cmp=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cmp++]=s[i]-'0';
		}
	}
	sort(a+1,a+cmp,self);
	for(int i=1;i<cmp;i++){
		cout<<a[i];
	}
	return 0;
} 
