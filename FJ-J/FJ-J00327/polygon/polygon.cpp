#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int a[5001];
void d(int i,int in,int la,long long sn){
	if(in==i){
		if(sn>a[la]*2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int j=la+1;j<=n;j++){
		d(i,in+1,j,sn+a[j]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){//i±ßÐÎ 
		d(i,0,0,0);
	}
	cout<<ans<<endl;
	return 0;
}

