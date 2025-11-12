#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,q,js[N];
int f(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='b'){
			return i;
		}
	}
}
int main(){
	freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		js[i]=f(a)-f(b);
	}
	for(int i=1;i<=q;i++){
		int kg=0;
		string a,b;
		cin>>a>>b;
		int k=f(a)-f(b);
		for(int i=1;i<=n;i++){
			if(k==js[i]){
				kg=1;
				cout<<1<<endl;
				break;
			}
			
		}
		if(kg==0){
			cout<<0<<endl;
		}
	}
	return 0;
}
