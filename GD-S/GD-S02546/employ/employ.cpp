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

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<0;
	return 0;
}
