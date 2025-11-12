#include<bits/stdc++.h>
using namespace std;
int a[5005][2];
int n,m;
void poly(int sam,int maxs,int s){
	for(int i=s+1;i<=n;i++){
		if(a[i][1]==0&&sam+a[i][0]>2*max(a[i][0],maxs)) m=(m+1)%998244353;
		a[i][1]=1;
		poly(sam+a[i][0],max(a[i][0],maxs),i);
		a[i][1]=0;
	}
}
int main(){
	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][0];
	poly(0,0,0);
	cout<<m;
	return 0;
}

