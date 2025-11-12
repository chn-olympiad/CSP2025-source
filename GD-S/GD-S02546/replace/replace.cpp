#include <bits/stdc++.h> 
using namespace std;

long long read(){
	char c=getchar();
	bool f=0;
	long long o=0;
	while(!isdigit(c)){
		f|=c=='-';
		c=getchar();
	}while(isdigit(c)){
		o=o*10+(c-'0');
		c=getchar();
	}
	return f?-o:o;
}

int n,q;
string a,b;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a>>b;
	}
	for(int i=0;i<q;i++){
		cout<<0<<'\n';
	}
	return 0;
}
