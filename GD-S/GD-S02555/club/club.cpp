#include<cstring>
#include<iostream>
using namespace std;
const int N=1e5+5;
int t,n,xx[N][3];
long long f[111][111][111];
int s[N*4],cnt[N*4];
void add(int l,int r,int i,int x){
	if(l==r){
		s[i]+=x;
		cnt[i]++;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=x) add(l,mid,i*2,x);
	else add(mid+1,r,i*2+1,x);
	s[i]+=x;
	cnt[i]++;
}
int query(int l,int r,int i,int p){
	if(l==r) return l*p;
	int mid=(l+r)>>1,sum;
	if(p<=cnt[i*2+1]) sum=query(mid+1,r,i*2+1,p);
	else sum=s[i*2+1]+query(l,mid,i*2,p-cnt[i*2+1]);
	return sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool fl=1;
		for(int i=1;i<=n;i++){
			cin>>xx[i][0]>>xx[i][1]>>xx[i][2];
			if(xx[i][3]) fl=0;
		}
		if(fl){
			long long sumb=0;
			memset(s,0,sizeof s);
			memset(cnt,0,sizeof cnt);
			for(int i=1;i<=n;i++){
				add(-2e4,2e4,1,xx[i][0]-xx[i][1]);
				sumb+=xx[i][1];
			}
			cout<<sumb+query(-2e4,2e4,1,n/2)<<"\n"; 
		}else{
			memset(f,0,sizeof f);
			long long ans=0;
			for(int l=1;l<=n;l++){
				int a=xx[l][0],b=xx[l][1],c=xx[l][2];
				for(int i=n/2;i>=0;i--){
					for(int j=min(n/2,n-i);j>=0;j--){
						for(int k=min(n/2,n-i-j);k>=0;k--){
							if(i) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a);
							if(j) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+b);
							if(k) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+c);
							ans=max(ans,f[i][j][k]);
						}
					}
				}	
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
