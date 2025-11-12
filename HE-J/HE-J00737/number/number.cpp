#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
string s;
long long a[17]={},sum=0,ans=0,ls;
int main(){
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)

	cin>>s;
	for(int i=0;i<=s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			sum++;
		}
	}
	for(int i=10;i>=0;i--){
		for(int j=a[i];j>=1;j--){
			cout<<i;
		}
	} 
	return 0;
} 
