#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e3+5;
int a[N][5],v[N],b[N];int n;
int x,ans=0;int d[N];
int c1[N],c2[N],c3[N],sum=0;
int rs1=0,rs2=0,rs3=0;
void init(){
	ans=0;sum=0;rs1=0,rs2=0,rs3=0;
	memset(v,0,sizeof(v));
	memset(d,0,sizeof(d));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
}
int T=0;
bool check(int mid){
	if(sum>=mid) return true;
	for(int i=1;i<=n;i++){
		if(rs1<n/2&&c1[i]!=0) sum+=c1[i],rs1++;
		else if(rs2<n/2&&c2[i]!=0) sum+=c2[i],rs2++;
		else if(rs3<n/2&&c3[i]!=0) sum+=c3[i],rs3++;
	}
	return sum>=mid;
}
void dfs(int k,int myz){
	if(k>=n){
		ans=max(ans,myz);
		return ;
	}
	ans=max(ans,myz);
	for(int i=k+1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(!v[i]&&d[j]<n/2){
				d[j]++;
				v[i]=1;
				dfs(i,myz+a[i][j]);
				v[i]=0;
				d[j]--;
			}
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--){
		init();
		cin>>n;
		x=n/2;
		int isz1=1,isz2=1,isz3=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if(j==1&&a[i][j]!=0) isz1=0;
				if(j==3&&a[i][j]!=0) isz3=0;
				if(j==2&&a[i][j]!=0) isz2=0;
			}
		}
		if(isz2&&isz3){
//			cout<<"#";
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>=n-x+1;i--) ans+=b[i];
			cout<<ans<<'\n';
			continue;
		}
		else if(isz1&&isz2){
			for(int i=1;i<=n;i++){
				b[i]=a[i][3];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>=n-x+1;i--) ans+=b[i];
			cout<<ans<<'\n';
			continue;
		}
		else if(isz1&&isz3){
			for(int i=1;i<=n;i++){
				b[i]=a[i][2];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>=n-x+1;i--) ans+=b[i];
			cout<<ans<<'\n';
			continue;
		}
		else if(isz3&&!isz1&&!isz2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++) ans+=a[i][j];
			}
			cout<<ans<<'\n';
		}
		else if(n<=30){
//			T=0;
			ans=0;
			dfs(0,0);
//			cout<<T<<" ";
			cout<<ans<<'\n';
		}
		else{
			ans=0;
			for(int i=1;i<=n;i++){
				int minn=INT_MAX;
				for(int j=1;j<=3;j++){
					minn=min(minn,a[i][j]);
				}
				sum+=minn;
				c1[i]=a[i][1]-minn;
				c2[i]=a[i][2]-minn;
				c3[i]=a[i][3]-minn;
				if(c1[i]==0) rs1++;
				else if(c2[i]==0) rs2++;
				else rs3++;
			}
			int l=0,r=1e9;
			while(l<=r){
				int mid=l+r>>1;
				if(check(mid)){
					l=mid+1;
					ans=mid;
				}
				else r=mid-1;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}











