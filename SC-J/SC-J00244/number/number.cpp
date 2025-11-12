#include<bits/stdc++.h>
using namespace std;
int a[1000010],ii;
bool cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++ii]=s[i]-'0';
		}
	}
	sort(a+1,a+ii+1,cmp);
	for(int i=1;i<=ii;i++){
		cout<<a[i];
	}
	return 0;
}