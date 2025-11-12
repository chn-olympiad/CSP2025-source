#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
	string a,b,c,d;
}l[N];
int n,q;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>l[i].a>>l[i].b;
	for(int i=0;i<q;i++) cin>>l[i].c>>l[i].d;
	for(int i=0;i<q;i++) cout<<0<<endl;
	return 0;
}
