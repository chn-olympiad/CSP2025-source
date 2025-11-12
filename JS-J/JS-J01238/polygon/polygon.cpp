#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull n,a[100005],sum,ans,maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ull i=1;i<=n;i++) cin>>a[i],sum+=a[i],maxx=max(maxx,a[i]);
	if(n<3){
		cout<<0<<endl;
	}else if(n==3){
		if(sum>max(a[1],max(a[2],a[3]))*2) cout<<1<<endl;
		else cout<<0<<endl;
	}else if(n==4){
		if(sum-a[4]>max(a[1],max(a[2],a[3]))*2) ans++;
		if(sum-a[3]>max(a[1],max(a[2],a[4]))*2) ans++;
		if(sum-a[2]>max(a[1],max(a[3],a[4]))*2) ans++;
		if(sum-a[1]>max(a[2],max(a[3],a[4]))*2) ans++;
		if(sum>max(max(a[1],a[4]),max(a[2],a[3]))*2) ans++;
		cout<<ans<<endl;
	}else if(maxx==1){
		for(ull i=3;i<=n;i++){
			ull ansans=1,modmod=1;
			for(ull j=n;j>n-i;j--,modmod++){
				ansans*=j;
				ansans/=modmod;
				ansans=ansans%998244353;
			}
			ans+=ansans;
			ans=ans%998244353;
		}
		cout<<ans<<endl;
	}else{
		cout<<"......\n";
	}
	return 0;
}
