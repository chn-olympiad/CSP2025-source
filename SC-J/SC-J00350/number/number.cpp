#include<bits/stdc++.h>
using namespace std;
string s;
int k;
int a[100005];
void f1(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++k]=s[i]-'0';
		} 
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	f1();
	return 0;
}