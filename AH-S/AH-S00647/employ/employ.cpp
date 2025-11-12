#include<bits/stdc++.h>
using namespace std;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		int x=s.size();
		for(int i=0;i<x;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	return 0;
}
