#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N][N],sum[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int m=n/2;
		for(int j=1;j<=n;j++){ 
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j][2]<a[j][3]) swap(a[j][2],a[j][3]);
			if(a[j][1]<a[j][2]) swap(a[j][1],a[j][2]);
			if(a[j][2]<a[j][3]) swap(a[j][2],a[j][3]);
			sum[i]+=a[j][1];
		}
	}
	for(int i=1;i<=t;i++) cout<<sum[i]<<'\n';
	return 0;
	//就算今天败在这里，也迟早有一天要拿回自己的荣耀才是 
}
