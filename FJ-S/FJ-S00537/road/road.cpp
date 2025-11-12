#include<bits/stdc++.h>
using namespace std;
struct road{
	long long a,b,cost;
}a[100005];
struct countryside{
	long long cost;
	long long c[1005];
}b[100005];
long long n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].cost;
		ans+=a[i].cost;
	}
	for(long long i=1;i<=k;i++){
		cin>>b[i].cost;
		for(int j=1;j<=n;j++){
			cin>>b[i].c[j];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

