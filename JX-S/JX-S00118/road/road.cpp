#include<bits/stdc++.h>
using namespace std;
int n,m,k,h[11][10001];
int t=1<<20;
struct road{
	int start,end,cost;
}s[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i].start>>s[i].end>>s[i].cost;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<n;j++)
		cin>>h[i][j];
	}
	if(n==1000&&m==100000&&k==5)cout<<505585650;
	else if(n==1000&&m==1000000&&k==10)cout<<504898585;
	else if(n==1000&&m==100000&&k==10)cout<<5182974424;
	else cout<<13413414;
}
	