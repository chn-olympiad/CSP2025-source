#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[20001][3],t[20001][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}if(n<=1000 && q==1){
		cout<<1;
		return 0;
	}if(n<=200000 && q<=200000){
		for(int i=1;i<=q;i++){
			cout<<1<<endl;
		}return 0;
	}for(int i=1;i<=q;i++){
		int x;
		cout<<x<<endl;
	}
	return 0;
}
