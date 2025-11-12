#include<bits/stdc++.h>
using namespace std;
int d[100005];
int tb[10005][10005];
int main(){
	
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	
	int sb;
	int s=0;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		d[i]=c;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>sb;
		}
	}
	sort(d+1,d+m+1);
	for(int i=1;i<=n-1;i++){
		s+=d[i];
	}
	cout<<s;
	return 0;
} 
