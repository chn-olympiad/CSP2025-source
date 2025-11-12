#include<bits/stdc++.h>
using namespace std;
int a[112345];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;cin>>x>>y>>z;
			a[i]=x;
		}
		sort(a+1,a+1+n,cmp);
		long long ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
	} 
	return 0;
}
