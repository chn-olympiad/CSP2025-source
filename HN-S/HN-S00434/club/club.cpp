#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N],b[N],c[N],s[N];
int t,n;
int q=0,w=0,e=0;
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			s[i]=a[i]+b[i]+c[i];
			if(b[i]==0) w++;
			if(c[i]==0) e++;
		}
		if(w==n && e==n){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans<<'\n';
		}
		else if(w!=n && e==n){
			for(int i=1;i<n;i+=2){
				int na=abs(a[i]-a[i+1]);
				int nb=abs(b[i]-b[i+1]);
				if(na<nb){
					ans+=max(b[i],b[i+1])+min(a[i],a[i+1]);
				}
				else{
					ans+=max(a[i],a[i+1])+min(b[i],b[i+1]);
				}
			}
			cout<<ans<<'\n';
		}
		else if(n==2){
			int na=max(a[1]+b[1+1],a[1]+c[1+1]);
			int nb=max(b[1]+c[1+1],b[1]+a[1+1]);
			int nc=max(c[1]+b[1+1],c[1]+a[1+1]);
			cout<<max(max(max(na,nb),max(nb,nc)),max(na,nc))<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n-i;j++){
					if(s[j]<s[j+1]){
						swap(s[j],s[j+1]);
						swap(a[j],a[j+1]);
						swap(b[j],b[j+1]);
						swap(c[j],c[j+1]);
					}
				}
			}
			for(int i=1;i<=n/2;i++){
				int na=max(a[i*2-1]+b[i*2],a[i*2-1]+c[i*2]);
				int nb=max(b[i*2-1]+c[i*2],b[i*2-1]+a[i*2]);
				int nc=max(c[i*2-1]+b[i*2],c[i*2-1]+a[i*2]);
				ans+=max(max(max(na,nb),max(nb,nc)),max(na,nc));
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
