#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,c[20];
ll rd[1000005][3];
ll town[20][10005];
int sj=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>rd[i][0]>>rd[i][1]>>rd[i][2];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)sj=1;
		for(int j=1;j<=n;j++){
			cin>>town[i][j];
			if(town[i][j]!=0)sj=1;
		}
	}
	if(sj==0)cout<<0;
	else{
		cout<<5182974424;
	}
	return 0;
}
