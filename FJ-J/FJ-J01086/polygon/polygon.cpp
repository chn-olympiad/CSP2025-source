#include<bits/stdc++.h>
using namespace std;
int n,a[5005],l,r,d[5005],as[5005],sj=1;
long long ans;
long long jc(int ax,int by){
	int jsans=1;
	for(int i=ax;i<=by;i++){
		jsans*=i-ax+1;
	}
	return jsans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		as[i]=as[i-1]+a[i];
	}sort(a+1,a+n+1);
	while(a[n]>as[n-1]){
		n--;
	}for(int i=3;i<=n;i++){
		sj*=(i-1);
		for(int j=i;j<=n;j++){
			for(int z=i-1;z<j;z++){
				if(as[z]-as[z-i+1]>a[j]){
					ans+=jc(z-i+2,j-1)/sj;
					ans%=998244353;
				}
			}
		}
	} if(n==3&&(a[2]+a[3])>a[1]&&(a[1]+a[3])>a[2]&&(a[1]+a[2])>a[3]){
		cout<<1;
	}else cout<<0;
	if(n!=3)cout<<ans;
	return 0;	
}
