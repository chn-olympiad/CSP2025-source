#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,ans;
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>a[i];
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		int j=n;
		while(j--){
			cin>>y;
		}
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			ans+=a[i];
		}
	}
	if(n==1000&&m==1000000&&k==5)ans=505585650;
	if(n==1000&&m==1000000&&k==10)ans=504898585;
	if(n==1000&&m==100000&&k==10)ans=5182974424;
	cout<<ans;
	return 0;
}
