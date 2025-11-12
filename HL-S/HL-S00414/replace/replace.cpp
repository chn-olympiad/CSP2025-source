#include<bits/stdc++.h>
using namespace std;
const int X=2*1e5+5;
struct str{
	string s1,s2,t1,t2;
}a[X];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>a[i].t1>>a[i].t2;
	}
	return 0;
} 
