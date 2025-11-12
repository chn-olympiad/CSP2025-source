#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
long long a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        if(n==2){
			int d=a[1]+b[2],e=a[1]+c[2],f=b[1]+a[2],g=b[1]+c[2],u=c[1]+a[2],v=c[1]+b[2];
			int ans=-1;
			ans=max(ans,max(d,max(e,max(f,max(g,max(u,v))))));
			cout<<ans<<endl;
			return 0;
		}
		else
        sort(a+1,a+n+1);
        for(int i=n;i>n/2;i--){
            ans=ans+a[i];
        }
        cout<<ans<<endl;
    }
}
