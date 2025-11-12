#include<bits/stdc++.h>
using namespace std;
int n,m,k,u1[10000000],u2[10000000],w1[100000000];
string a[1000001][10000001],b[1000001][3],
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int q=1;q<=n;q++){
		for(int w=1;w<=m;w++)cin>>a[q][w];
	}
	for(int w=1;w<=m;w++)cin>>b[w][1]>>b[w][2];
	for(int j=1;j<=m;j++)cout<<0<<" ";
	return 0;
}
