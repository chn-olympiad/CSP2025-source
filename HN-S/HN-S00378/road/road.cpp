#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int h,d,v;
}r[1000000];
struct village{
	int c,ro[10000];
}a[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++){
		cin>>r[i].h>>r[i].d>>r[i].v;
		ans+=r[i].v;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;i++){
			cin>>a[i].ro[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
//Karmatic!Karmatic Time Trio
