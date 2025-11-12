#include<bits/stdc++.h>
using namespace std;
string s;
long long t[15];
long long a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		a=s[i]-'0';
		if(a>=0&&a<=9){
			t[a]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]){
			cout<<i;
			t[i]--;
		}
		
	}
	return 0;
}