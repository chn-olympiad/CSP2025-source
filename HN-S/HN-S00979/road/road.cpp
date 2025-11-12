#include<bits/stdc++.h>
using namespace std;
int w[10086],c[10086];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
	}
	sort(w+1,w+m+1);
	for(int i=1;i<=n/2+1;i++){
		sum+=w[i];
	}
	return 0;
}
