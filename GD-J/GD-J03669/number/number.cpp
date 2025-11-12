#include<bits/stdc++.h>
using namespace std;
long long a[20],v,n=0;
string s;
int main(){
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
}
