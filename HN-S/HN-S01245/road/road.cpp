#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000010][5],b[1000010],c[20],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans+=a[i][3];
	}
	cout<<ans;
	return 0;
}


