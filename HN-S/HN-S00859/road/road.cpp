#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,m,k;

int main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	//ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	int qw[101][112];
	int a,s,d;
	for(int i=1;i<=m;i++){
		
		cin>>a>>s>>d;
		qw[a][s]=d;
		qw[s][a]=d;
	}
	int td[1001][1001];
	int cxjz[10];
	for(int i=1;i<=k;i++){
		cin>>cxjz[i];
		for(int j=1;j<=n;j++){
			int po,oi,iu;
			cin>>po>>oi>>iu;
			td[po][oi]=iu;
			td[oi][po]=iu;
		}
	}
	cout<<m*d;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
