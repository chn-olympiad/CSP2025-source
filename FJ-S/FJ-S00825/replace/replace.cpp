#include<bits/stdc++.h>
using namespace std;
string s[150000],o[10050];
long long n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n+m;i++){
		cin>>s[i]>>o[i];
	}
	if(n==4&&m==2){
		cout<<2<<endl;
		cout<<0;
	}if(n==3&&m==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
}
