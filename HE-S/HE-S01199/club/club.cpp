#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+10;
int id[N];
int sz[N];
int minn[N];
int a[N][5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			id[i]=sz[i]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int p=1;
			if(a[i][2]>a[i][1])p=2;
			if(a[i][3]>a[i][p])p=3;
			id[i]=p;
			sz[p]++;
			ans+=a[i][p];
		} 
		if(sz[1]>n/2){
			int cnt=0;
			for(int i=1;i<=n;i++){
				int maxn=0;
				maxn=max(a[i][2],a[i][3]);
				if(id[i]==1)minn[++cnt]=a[i][1]-maxn;
			}
			sort(minn+1,minn+cnt+1); 
			for(int i=1;i<=sz[1]-n/2;i++)ans-=minn[i]; 
		}
		else if(sz[2]>n/2){
			int cnt=0;
			for(int i=1;i<=n;i++){
				int maxn=0;
				maxn=max(a[i][1],a[i][3]);
				if(id[i]==2)minn[++cnt]=a[i][2]-maxn;
			}
			sort(minn+1,minn+cnt+1);
			for(int i=1;i<=sz[2]-n/2;i++)ans-=minn[i]; 
		}
		else if(sz[3]>n/2){
			int cnt=0;
			for(int i=1;i<=n;i++){
				int maxn=0;
				maxn=max(a[i][1],a[i][2]);
				if(id[i]==3)minn[++cnt]=a[i][3]-maxn;
			}
			sort(minn+1,minn+cnt+1);
			for(int i=1;i<=sz[3]-n/2;i++)ans-=minn[i]; 
		}
		cout<<ans<<'\n';
	} 
	return 0;
} 
