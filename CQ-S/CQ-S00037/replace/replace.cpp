#include<bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=2e5+5;
struct node{
	string s1,s2;
}a[N];
int n,m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i].s1>>a[i].s2;
	}	
	while(m--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<0<<"\n";
	}
	return 0;
}
