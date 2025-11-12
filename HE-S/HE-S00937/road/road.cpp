#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v,w;
};
int uu,vv,ww;
long long sum;
vector<node> st[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>uu>>vv>>ww;
		sum+=ww;
	}
	cout<<sum*2;
	return 0;
} 
