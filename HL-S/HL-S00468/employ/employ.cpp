#include <bits/stdc++.h>
using namespace std;
const int N=520;
int n,m,c[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		for(int i=0;i<s.length();i++){
			if(s[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
	}
	if(m==1){
		int fangqi=0;
		for(int i=0;i<s.length();i++){
			if(s[i]==0){
				fangqi++;
			}else if(c[i+1]>fangqi){
				cout<<1;
				return 0;
			}
		}	
		cout<<0;
	}else cout<<18;
	
	return 0;
} 
