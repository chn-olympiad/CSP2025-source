#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int j=9;j>=0;j--){
		for(int i=0;i<s.size();i++){
			if(s[i]==j+'0'){
				cout<<s[i];
			}
		}	
	}
	
} 