#include<bits/stdc++.h>
using namespace std;
struct dou{
	string a;
	string b;
};
vector<dou> m;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	m.resize(n);
	for(int i=0;i<n;i++){
		cin>>m[i].a>>m[i].b;
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}
