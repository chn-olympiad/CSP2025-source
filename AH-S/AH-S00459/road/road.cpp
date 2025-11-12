#include<bits/stdc++.h>
using namespace std;
int main(){
  	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,as=0;
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		as+=c;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>a;
			as+=a;
		}
	}
	cout<<as;
	return 0;
}
