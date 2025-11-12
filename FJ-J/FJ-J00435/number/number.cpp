#include <iostream>
#include <string>
using namespace std;
string s;
int a[1000005],n,b[9];
int main(){
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if('0'<=s[i-1]&&s[i-1]<='9'){
			n++;
		    a[n]=s[i-1]-'0';
		}
	}
	for(int i=1;i<=n;i++){
		b[a[i]]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			cout<<i;
		}
	}
}
