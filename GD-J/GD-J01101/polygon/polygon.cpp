#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxx,sum,f[500][500][500],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		sum+=a[i];
	}
	f[1][a[1]][a[1]]=0;
	f[2][max(a[1],a[2])][a[1]+a[2]]=0;
	if(max(max(a[1],a[2]),max(a[2],a[3]))*2<a[1]+a[2]+a[3]){
		f[3][max(max(a[1],a[2]),max(a[2],a[3]))][a[1]+a[2]+a[3]]=1;
	}else{
		f[3][max(max(a[1],a[2]),max(a[2],a[3]))][a[1]+a[2]+a[3]]=0;
	}
	for(int i=4;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=sum;k>=j;k--){
				f[i][j][k]=f[i-1][j-a[j]][k-a[j]]+1;
			}
		}
	}
	for(int i=3;i<=n;i++){
		ans+=f[i][maxx][sum];
	}
	cout<<ans;
	return 0;
}
