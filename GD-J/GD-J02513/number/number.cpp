#include<bits/stdc++.h>
using namespace std;
string s;
char num[1000005];
int len=0;
bool cmp(char a,char b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			num[++len]=s[i]; 
		}
	}
	sort(num+1,num+1+len,cmp);
	for(int i=1;i<=len;i++){
		cout<<num[i];
	}
    return 0;
}
