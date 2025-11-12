#include <bits/stdc++.h>
using namespace std;
long long a[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
	for(int i=0;i<s.length();i++){
		a[char(s[i]-'0')]++;
	}	
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
} 