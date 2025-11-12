#include<bits/stdc++.h>
using namespace std;
string s;
int n,ai=0;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ai]=s[i]-'0';
			ai++;
		}
	}
	sort(a,a+ai);
	ai--;
	for(;ai>=0;ai--){
		cout<<a[ai];
	}
} 
