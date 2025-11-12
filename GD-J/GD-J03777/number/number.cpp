#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100];//¸Ä·¶Î§
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		char c=s[i]-48;
		
		a[c]++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			cout<<i;
			a[i]-=1;
		}
		
	}
	return 0;
} 

