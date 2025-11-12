#include<bits/stdc++.h>
using namespace std;
long long n[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	scanf("%s",&s);
	for(long long i=0;i<s.size();i++){
		if(int(s[i])>=int('0')&&int(s[i])<=int('9')){
			n[int(s[i])-int('0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(n[i]>0){
			while(n[i]--){
				cout<<i;
			}
		}
	}
	return 0;
}
