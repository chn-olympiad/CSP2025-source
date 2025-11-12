#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[11];
int main(){	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		char o=s[i];
		if(o>='0'&&o<='9')
			a[o-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			int x=a[i];
			while(x>0){
				cout<<i;
				x--;
			}
		}
	}
	return 0;
} 
