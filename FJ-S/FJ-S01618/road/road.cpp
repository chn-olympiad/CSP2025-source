#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],b[N],c[N],s;	
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
		s+=c[i];
	}
	cout<<s;
	return 0;
}
