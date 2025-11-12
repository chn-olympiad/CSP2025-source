#include<bits/stdc++.h>
using namespace std;
int n,a[5010],maxd,j,z;
bool v[5010]={0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxd=max(a[i],maxd);
	}
	if(n<=10){
		for(int i=0;i<=n;i++)
		for(int u=0;u<=n;u++)
		for(int o=0;o<=n;o++)
		for(int p=0;p<=n;p++)
		for(int l=0;l<=n;l++)
		for(int k=0;k<=n;k++)
		for(int j=0;j<=n;j++)
		for(int h=0;h<=n;h++)
		for(int y=0;y<=n;y++)
		for(int t=0;t<=n;t++)if(a[i]+a[o]+a[p]+a[u]+a[k]+a[l]+a[j]+a[y]+a[t]+a[h]>maxd*2)z++;
	}
	cout<<z/6699047;
	return 0;
}
