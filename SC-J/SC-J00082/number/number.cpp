#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			while(a[i]--){
				cout<<i;
			}
		}
	}
	return 0;
}