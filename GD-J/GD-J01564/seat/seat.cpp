#include<bits/stdc++.h>
using namespace std;
long long m,n,a[1005],b[1005],c[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
		c[i]=i;
	}
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
				swap(c[i],c[j]);
			}
		}
	}
	int x=0;
	for(int i=1;i<=n*m;i++){
		if(c[i]==1) x=i;
	}
	long long sum=0;
	for(int i=1;i<=m;i++){
		sum+=n;
		if(sum>=x){
			if(i%2==1) cout<<i<<" "<<(x-(sum-n));
			else cout<<i<<" "<<(sum-x)+1; 
			break;
		}
	}
	return 0;
} 
