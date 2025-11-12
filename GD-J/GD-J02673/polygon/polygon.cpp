#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int vis[5005][5005],vmax[5005][5005],a[5005];
	int n,shu,cmax=0;
	cin>>n;
	int num=0;
	if(n==3){
		for(int i=1;i<=3;i++){
			cin>>shu;
			num=num+shu;
			cmax=max(cmax,shu);
		}
		if(num>cmax*2){
			cout<<"1"<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;i<=n;j++){
			vis[i][j]=vis[i-1][j]-a[i];
			if(vmax[i-1][j]==a[i-1]){
				vmax[i][j]=max(vmax[i][j-1],a[j]);
			}
			else{
				vmax[i][j]=vmax[i-1][j];
			}
			if(vis[i][j]>vmax[i][j]*2){
				num=(num+1)%998244353;
			}
		}
	}
	cout<<num<<endl;
	return 0;
} 
