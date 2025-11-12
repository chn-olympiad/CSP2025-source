#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int len;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[len]=s[i]-'0';
			len++;
		}
	}sort(a,a+len,cmp);
	for(int i=0;i<len;i++){
		cout<<a[i];
	}
	return 0;
}
