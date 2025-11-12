#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
long long a[10],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<=l;i++){
		if('0'<=s[i]&&s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++)cout<<i;
	}	
	return 0;
} 
