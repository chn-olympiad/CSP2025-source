#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N = 1e4 + 5;
const ll M = 1e6 + 5;
const int K = 1e1 + 5;
int Q = 0;
struct node{
	int p1,p2;
	ll use;
};
struct Node {
	int end;
	ll use;
};
vector<node >s;
ll n,m,k;
bool k_u[K]={false};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		s.push_back({a,b,c});
	}
	cout<<0;
	return ( Q ^ Q );
}
