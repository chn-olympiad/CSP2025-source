#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		int a=s[i]-48;
		if(a>=0&&a<10)
			t[a]++;
	}
	for(int i=9;i>=0;i--){
		while(t[i]!=0){
			cout<<i;
			t[i]--;
		}
	}

	return 0;
}
