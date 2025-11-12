#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[100005][4],ans,sx[100005],sy[100005],sz[100005],ca,cb,cc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		ca=cb=cc=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) ans+=a[i][1],sx[++ca]=max(a[i][2],a[i][3])-a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) ans+=a[i][2],sy[++cb]=max(a[i][1],a[i][3])-a[i][2];
			else ans+=a[i][3],sz[++cc]=max(a[i][1],a[i][2])-a[i][3];
		}
		if(ca>n/2){
			sort(sx+1,sx+1+ca);
			for(int i=ca;i>n/2;i--) ans+=sx[i];
		} else if(cb>n/2){
			sort(sy+1,sy+1+cb);
			for(int i=cb;i>n/2;i--) ans+=sy[i];
		}else{
			sort(sz+1,sz+1+cc);
			for(int i=cc;i>n/2;i--) ans+=sz[i];
		}
		cout<<ans<<"\n";
	}
}
