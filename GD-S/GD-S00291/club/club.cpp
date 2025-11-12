#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,a[N][4],s[N][4],sy[N],e[N],ans,cn1,cn2,cn0,p,sp;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T; 
	while(T--){
		cin>>n,cn1=cn2=cn0=ans=0,p=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int mx=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][0]==mx) s[++cn0][0]=i,ans+=a[i][0],sy[i]=a[i][0]-max(a[i][1],a[i][2]);
			else if(a[i][1]==mx) s[++cn1][1]=i,ans+=a[i][1],sy[i]=a[i][1]-max(a[i][0],a[i][2]);
			else s[++cn2][2]=i,ans+=a[i][2],sy[i]=a[i][2]-max(a[i][1],a[i][0]);
		}
		if(cn0>n/2) p=0,sp=cn0;
		if(cn1>n/2) p=1,sp=cn1;
		if(cn2>n/2) p=2,sp=cn2;
		if(p==-1){cout<<ans<<"\n";continue;}
		for(int i=1;i<=sp;i++) e[i]=sy[s[i][p]];
		sort(e+1,e+sp+1);
		for(int i=1;i<=sp-n/2;i++) ans-=e[i];
		cout<<ans<<"\n";
	}
	return 0;
}
