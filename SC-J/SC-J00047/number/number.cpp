#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
short a[N];
bool check(char x){
	return x<='9' && x>='0';
}
bool cmp(int p,int q){
	return p>q;
}string s;int len=1;
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;string ans;cin>>ans;
	for(int i=0;i<(int)s.size();i++){
		if(check(s[i])){
			a[len]=(s[i]-'0');len++;
		}
	}sort(a+1,a+len+1,cmp);
	for(int i=1;i<len;i++){
		cout<<a[i];
	}return 0;
}