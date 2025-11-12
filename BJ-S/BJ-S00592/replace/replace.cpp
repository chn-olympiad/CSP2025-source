#include<bits/stdc++.h>
using namespace std;
int n,q;
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++{
		cin>>s>>s;
	}
	for(int i=1;i<=n;i++){
		cin>>s;
		int a=0;
		for(int j=0;i<s.size();j++){
			if(s[i]=='b'){
				a++;
			}
		}
		cin>>s;
		int b=0;
		for(int j=0;i<s.size();j++){
			if(s[i]=='b'){
				b++;
			}
		}
		if(a==b){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}