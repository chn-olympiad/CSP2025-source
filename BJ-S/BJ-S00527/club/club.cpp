#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int t,a[N][4],r[4],p1[N],p2[N],p3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		memset(r,0,sizeof(r));
		long long n,h,ans=0,k1=1,k2=1,k3=1;
		cin>>n;
		for(int i=1;i<=n;i++) p1[i]=1e9,p2[i]=1e9,p3[i]=1e9;
		h=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int k=max(a[i][1],max(a[i][2],a[i][3]));
			int mid=a[i][1]+a[i][2]+a[i][3]-k-min(a[i][1],min(a[i][2],a[i][3]));
			for(int j=1;j<=3;j++){
				if(a[i][j]==k){
					r[j]++;
					ans+=a[i][j];
					if(j==1) p1[k1]=k-mid,k1++;
					else if(j==2) p2[k2]=k-mid,k2++;
					else if(j==3) p3[k3]=k-mid,k3++;
					break;
				}
			}
		}
		bool flag=1;
		for(int i=1;i<=3;i++){
			if(r[i]>h) flag=0;
		}
		if(flag){
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=3;i++){
			if(r[i]>h){
				if(i==1) sort(p1+1,p1+k1);
				else if(i==2) sort(p2+1,p2+k2);
				else if(i==3) sort(p3+1,p3+k3);
				int fs=1,q=r[i]-h;
				while(q--){
					if(i==1) ans-=p1[fs];
					else if(i==2) ans-=p2[fs];
					else if(i==3) ans-=p3[fs];
					fs++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
