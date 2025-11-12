#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,q,la[N],ba[N],bb[N];
string a[N],b[N],c,d;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i,j;
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		la[i]=a[i].size();
		for(j=0;j<la[i];j++){
			if(a[i][j]=='b'){
				ba[i]=j;
			}
			if(b[i][j]=='b'){
				bb[i]=j;
			}
			if(ba[i]&&bb[i]) break ;
		}
	}
	while(q--){
		cin>>c>>d;
		int lc=c.size(),ld=d.size();
		if(lc!=ld){
			cout<<0<<endl;
			continue ;
		}
		int bc=-1,bd=-1;
		for(i=0;i<lc;i++){
			if(c[i]=='b'){
				bc=i;
			}
			if(d[i]=='b'){
				bd=i;
			}
			if(bc&&bd) break ;
		}
		int ans=0;
		for(i=1;i<=n;i++){
			if(bd-bc==bb[i]-ba[i]){
				if(la[i]-ba[i]<=lc-bc&&la[i]<=lc) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
