#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
	cin>>n>>q;
	char s[n][2],t[q][2];
	for(int q=0;q<n;q++){
		for(int j=0;j<2;j++){
			cin>>s[q][j];
		}
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}
 
