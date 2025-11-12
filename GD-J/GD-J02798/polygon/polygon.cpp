#include<bits/stdc++.h>
using namespace std;
int qy(int x,int y,int cs){
	for(int i=0;i<=cs-1;i++){
		long long j=i*y;
		while(j>=cs){
			j-=cs;
		}
		if(j==x){
			return i;
			break;
		}
	}
}
long long cp(int n,int m){
	if(n-m<m) m=n-m;
	long long js1=1; 
	for(int i=n;i>=n-m+1;i--){
		js1*=i;
		js1=js1%998244353;
	}
	long long js2=1;
	for(int i=1;i<=m;i++){
		js2*=i;
		js2=js2%998244353;
	}
	return qy(js1,js2,998244353);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn) maxn=a[i];
	}
	if(n==3) {
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]){
			cout<<"1"<<endl;
		}
		else cout<<"0";
		return 0;
	}
	if(maxn==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=cp(n,i);
		}
		cout<<ans;
		return 0;
	}
} 
