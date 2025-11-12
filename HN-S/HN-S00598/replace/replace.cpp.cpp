#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q;
struct node{
	string s;
	string t;
}a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].t;
	}
	for(int i=1;i<=q;i++){
		cin>>b[i].s>>a[i].t;
	}
	return 0;
}

