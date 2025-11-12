#include<bits/stdc++.h>
using namespace std;
long long n,q;
struct node{
	string s1;
	string s2;
}n[200005],t[200005]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>n[i].s1>>n[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].s1>>t[i].s2;
	}
	return 0;
} 
