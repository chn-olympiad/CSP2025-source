#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,int>f[105];
int a[105],x,y,d,cnt,cnt1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1])cnt1++;
	}
	d=1;
	x=1,y=1;
	f[1]={1,1};
	cnt=1;
	while(cnt!=n*m){
		if((y==n&&d==1)||(y==1&&d==-1))x++,d=-d;
		else y+=d;
		f[++cnt]={x,y};
	}
	cout<<f[cnt1].first<<" "<<f[cnt1].second;
	return 0;
}
