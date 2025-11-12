#include<bits/stdc++.h>
using namespace std;
string s;
int t[18];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++){
		if('0'<=s[i]<='9')
			t[s[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		if(t[i]){
			for(int j=1;j<=t[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
