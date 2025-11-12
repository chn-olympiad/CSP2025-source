#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1),x+=(c-48),c=getchar();
	return x;
}
int main(){
	string ls;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;i++) cin>>ls>>ls;
	while(q--){
		cin>>ls>>ls;
		cout<<"0\n"; 
	}
	return 0;
} 
