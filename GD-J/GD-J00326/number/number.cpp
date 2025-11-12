#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long arr[30]={},l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9)arr[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(long long j=0;j<arr[i];j++)cout<<i;
	}
	return 0;
} 
