#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[N][4],b[N];
int t,n;
vector<int> x,y,z;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		x.clear();
		y.clear();
		z.clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				 ans+=a[i][1],x.push_back(i);
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ans+=a[i][2],y.push_back(i);
			}else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				ans+=a[i][3],z.push_back(i);
			}
		}
		int top=0;
		int tag;
		int xs=x.size(),ys=y.size(),zs=z.size();
		if(xs>n/2) for(auto u:x) b[++top]=u,tag=1;
		if(ys>n/2) for(auto u:y) b[++top]=u,tag=2;
		if(zs>n/2) for(auto u:z) b[++top]=u,tag=3;
		int tmp=top-n/2;
		for(int i=1;i<=top;i++){
			int p=a[b[i]][tag];
			int q=-1;
			for(int j=1;j<=3;j++){
				if(j!=tag) q=max(q,a[b[i]][j]);
			}
			b[i]=p-q;
		}
		sort(b+1,b+top+1);
		for(int i=1;i<=tmp;i++) ans-=b[i];
		cout<<ans<<'\n';
	}
	return 0;
}
