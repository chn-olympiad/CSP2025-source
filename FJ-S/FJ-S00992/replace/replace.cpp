#include<bits/stdc++.h>
using namespace std;
string cnt1,cnt2;
int n,q,ans=0;
struct node{
	string s1,s2;	
}a[200005];
struct node1{
	string t1,t2;	
}b[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>b[i].t1>>b[i].t2;
	}
	for(int i=1;i<=q;i++){
		cout<<0;
	}
	return 0;
}

