#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int c[N];
int num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[++num]=s[i]-'0';
		}
	}
	sort(c+1,c+1+num);
	for(int i=num;i>=1;i--){
		if(c[i]==0&&i==num){
			cout<<0;
			return 0;
		}
		else{
			cout<<c[i];
		}
	}
	return 0;
}