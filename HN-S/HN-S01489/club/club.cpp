#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int t,a,b,c,v[10010],n,ans=0;
cin>>t;
while(t--){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		v[i]=a;
	}
	sort(v,v+n+1);
	for(int i=n;i>=n/2;i--){
		ans+=v[i];
	}
	cout<<ans<<endl;
}
	return 0;
}
