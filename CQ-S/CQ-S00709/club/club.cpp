#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005],maxn[100005],ans=0;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
while(t--){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
maxn[i]=max(a[i],max(b[i],c[i]));
	}sort(maxn+1,maxn+n+1);
	for(int i=n;i>n/2;i--){
		ans+=maxn[i];
	}cout<<ans<<"\n";
	ans=0;
}
	return 0;
}

