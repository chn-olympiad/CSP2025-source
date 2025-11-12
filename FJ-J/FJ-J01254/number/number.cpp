#include<bits/stdc++.h>
using namespace std;
string s;
string number[10]={"0","1","2","3","4","5","6","7","8","9"};
long long k=0;
long long n[10]={0};
int main(){
	freopen("number4.in","r",stdin);
	cin>>s;
	for(long long i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[s[i]-'0']++;
		}
	}freopen("number.out","w",stdout);
	for(long long i=9;i>=0;i--){
		for(long long j=0;j<n[i];j++)cout<<number[i];
	}return 0;
} 
