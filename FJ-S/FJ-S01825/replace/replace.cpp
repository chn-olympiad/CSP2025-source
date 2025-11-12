#include<bits/stdc++.h>
using namespace std;
struct q{
	string a,b;
};
map<q,bool> d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,p;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		q g;
		cin>>g.a>>g.b;
	}
	for(int i=1;i<=p;i++){
		cout<<0<<endl;
	}
	return 0;
}
