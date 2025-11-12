#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],n,m,k;
long long w,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
	for(int i=0;i<m;i++){
			cin>>a[i]>>b[i]>>c;
			w+=c;
	}
	for(int i=0;i<=m;i++){
		swap(a[i],b[i]);
		swap(a[i],b[i]);
	}
	cout<<w;
	return 0;
}

