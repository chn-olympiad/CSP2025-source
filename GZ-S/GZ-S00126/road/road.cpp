//GZ-S00126 贵阳市南明区华麟学校 娄芷淇 
#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,cnt,d[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		cnt+=c;
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n+1;j++)
			cin>>d[j];
	cout<<cnt;
	return 0;
}
