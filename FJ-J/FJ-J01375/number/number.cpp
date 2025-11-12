#include<bits/stdc++.h>
using namespace std;
bool f(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1001],j=0;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[j]=int(s[i]-'0');
			j++;
		}
	}
	sort(a,a+j,f);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
