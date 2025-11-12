#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N],w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>w[i];
		cnt+=w[i];
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
	}
	cout<<cnt;
	return 0;
}
