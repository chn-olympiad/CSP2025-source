#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a[200010][4];
ll f[200010][4];
ll g[200010];
ll s1,s2,s3,p,p1,p2,ans;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		for(ll i=1;i<=n;i++) for(ll j=0;j<=2;j++) f[i][j]=0;
		s1=0,s2=0,s3=0;ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) s1++;
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])s2++;
			else{
				if(a[i][1]==a[i][3]&&s1<n/2) s1++;
				else if(a[i][2]==a[i][3]&&s2<n/2) s2++;
				else s3++;
			}
		}
		if(s1>n/2) p=1,p1=2,p2=3;
		else if(s2>n/2) p=2,p1=1,p2=3;
		else if(s3>n/2) p=3,p1=1,p2=2;
		else{
			for(ll i=1;i<=n;i++)
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			cout<<ans<<endl;
			continue;
		}
		//cout<<p<<endl;
		ll z=0;
		for(ll i=1;i<=n;i++){
			if(max(a[i][1],max(a[i][2],a[i][3]))==max(a[i][p1],a[i][p2])) ans+=max(a[i][p1],a[i][p2]);
			else g[++z]=a[i][p]-max(a[i][p1],a[i][p2]),ans+=max(a[i][p1],a[i][p2]);
		}
		sort(g+1,g+1+z,cmp);
		for(ll i=1;i<=n/2;i++) ans+=g[i];
		cout<<ans<<endl;
    }
    return 0;
}
