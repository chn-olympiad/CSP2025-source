#include<bits/stdc++.h>
using namespace std;
int n,maxx,js,sum;
int a[5005],b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n;i--){
		sum+=a[i];
		if(sum>2*maxx) js++;
	}
	for(int j=1;j<=n-3;j++){
		int k=0;
		for(int z=n;z>=1;z--){
			b[++k]=sum-a[z];
			if(b[k]>=maxx*2&&a[z]!=maxx)js++;
			else if(b[k]>=a[2])js++;
			}
		}
		cout<<js;
}
