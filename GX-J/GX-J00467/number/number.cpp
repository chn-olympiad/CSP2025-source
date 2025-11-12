#include <iostream>
#include <math.h>
using namespace std;
long long i,j;
long long q[12];
int main(){
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]-'0'<10&&s[i]-'0'>=0){
			//cout<<s[i];
			q[s[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--){
		for(j=0;j<q[i];j++){
			cout<<i;
		}
	}
	
	return 0;
}
