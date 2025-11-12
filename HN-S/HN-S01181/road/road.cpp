#include<bits/stdc++.h>
using namespace std;
struct lu{
	int zuo,you,fei;
}a[10005];
int n,m,k,cun[11],b[10][10005];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].zuo>>a[i].you>>a[i].fei;
		ans+=a[i].fei;
	}
	for(int i=1;i<=k;i++){
		cin>>cun[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		
	}
	cout<<ans;
	return 0;
}
