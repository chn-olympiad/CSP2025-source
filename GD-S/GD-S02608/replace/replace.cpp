#include<bits/stdc++.h>
#define FILENAME "replace"
using namespace std;
const int N=2e5+10;

int read(){
	int x=0,k=1;char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*k;
}

string s[N][3];

int main(){
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		
	}
	cout<<0;
	return 0;
} 
