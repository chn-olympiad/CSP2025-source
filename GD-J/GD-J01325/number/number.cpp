#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N=1e6+5;
int a[N],num;
string s;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++num]=s[i]-'0';	
		} 
	}
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
