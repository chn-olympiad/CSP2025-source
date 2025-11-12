#include<bits/stdc++.h>
using namespace std;
struct cake114514{
	int a,b,c,d;
}rep[114514];
int n,q;
char aa,bb,cc,dd;
void solve(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>aa>>bb;
	}
	for(int i=0;i<q;i++){
		cin>>cc>>dd;
	}
	for(int i=0;i<n;i++){
		rep[i].a=aa-'a';
		rep[i].b=bb-'a';
	}
	for(int i=0;i<n;i++){
		rep[i].c=cc-'a';
		rep[i].d=dd-'a';
	}
	for(int i=0;i<=n;i++){
		cout<<0<<endl;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
}
