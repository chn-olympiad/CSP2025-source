#include <bits/stdc++.h>
using namespace std;
int t;
int n,ans;
int x[10005],y[10005],z[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>z[i];
		if(n==2){
			ans=max(x[1]+y[2],x[1]+z[2]);
			ans=max(ans,y[1]+max(x[2],z[2]));
			ans=max(ans,z[1]+max(x[2],y[2]));
			cout<<ans<<endl;
			continue;
		}
		bool f1=1,f2=1,f3=1;
		for(int i=1;i<=n;i++){
			if(x[i]) f1=0;
			if(y[i]) f2=0;
			if(z[i]) f3=0;
			if(!f1&&!f2&&!f3) break;
		}
		if(!f1&&!f2&&!f3){
			for(int i=1;i<=n;i++)
				ans+=max(x[i],max(y[i],z[i]));
			cout<<ans<<endl;
		}
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		sort(z+1,z+n+1);
		if(f1&&f2){
			for(int i=n;i>n/2;i--) ans+=z[i];
			cout<<ans<<endl;
		}
		else if(f1&&f3){
			for(int i=n;i>n/2;i--) ans+=y[i];
			cout<<ans<<endl;
		}
		else if(f2&&f3){
			for(int i=n;i>n/2;i--) ans+=x[i];
		}
		else if(f1){
			for(int i=n;i>n/2;i--) ans+=y[i];
			for(int i=n;i>n/2;i--) ans+=z[i];
			cout<<ans<<endl;
		}
		else if(f2){
			for(int i=n;i>n/2;i--) ans+=x[i];
			for(int i=n;i>n/2;i--) ans+=z[i];
			cout<<ans<<endl;
		}
		else if(f3){
			for(int i=n;i>n/2;i--) ans+=x[i];
			for(int i=n;i>n/2;i--) ans+=y[i];
			cout<<ans<<endl;
		}
	}
	return 0;
} 
