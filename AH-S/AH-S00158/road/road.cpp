//7.07 14.22 7.01 14.15  '11.15'    
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][12];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>m>>n>>k;
	int wn=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		wn+=w;
	}
	int an=0,cn=0;
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		int a;
		for(int j=1;j<=n;j++){
			cin>>a;
			an+=a;
		}
		cn+=min(c,an);
	}
	cout<<min(wn,cn);
	return 0;
}
