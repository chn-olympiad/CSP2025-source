#include<bits/stdc++.h>
#define int long long
const int N=1e5+5;
const int M=1005;
using namespace std;
int t,n,a[5][N],f[M][M],ans,num[4];
int cnt,b[N];
struct point{
	int id,val,op;
	bool operator<(const point&A)const{
		return val>A.val;
	}
}c[N*3];
bool vis[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<4;j++){
				cin>>a[j][i],num[j]+=a[j][i];
				c[++cnt].val=a[j][i];
				c[cnt].op=j,c[cnt].id=i;
			}
		}
		if(num[2]==0&&num[3]==0){
			for(int i=1;i<=n;i++)b[i]=a[1][i];
			sort(b+1,b+n+1);
			for(int i=1;i<=n/2;i++)ans+=b[n-i+1];
			cout<<ans<<"\n";
			continue;
		}
		if(n<=1000){
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++){
				for(int j=min(i,n/2);j>=0;j--){
					for(int k=min(i-j,min(i,n/2));k>=0;k--){
						if((i-j-k)>n/2)continue;
						if((i-j-k)!=0)f[j][k]=f[j][k]+a[3][i];
						if(j!=0)f[j][k]=max(f[j][k],f[j-1][k]+a[1][i]);
						if(k!=0)f[j][k]=max(f[j][k],f[j][k-1]+a[2][i]);
					}
				}
			}
			ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if((n-i-j)>n/2)continue;
					ans=max(ans,f[i][j]);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		num[1]=num[2]=num[3]=ans=0;
		sort(c+1,c+cnt+1);
		fill(vis+1,vis+n+1,false);
		for(int i=1;i<=cnt;i++){
			if(vis[c[i].id]==false&&num[c[i].op]<n/2){
				vis[c[i].id]=true,num[c[i].op]++;
				ans+=c[i].val;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}//65
