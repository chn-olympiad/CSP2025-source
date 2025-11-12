#include<bits/stdc++.h>
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int N=1e5+44,mod=2e4+10,SN=444;
int T,n,a[N][4],f[N],f2[SN][SN],s[N];
bool cmp1(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#if LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif
	cin>>T;
	while(T--){
		cin>>n;
		bool cha=0,chb=0;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2],cha=cha|(a[i][1]>0),chb=chb|(a[i][2]>0);
	//	for(int i=1;i<=n;i++)cout<<a[i][0]<<' '<<a[i][1]<<' '<<a[i][2]<<'\n';
		if(cha==0&&chb==0){
			int ans=0;
			for(int i=1;i<=n;i++)ans+=a[i][0];
			cout<<ans<<'\n';
			continue;
		}
		if(chb==0){
			int ans=0;
			for(int i=1;i<=n;i++)f[i]=0,s[i]=a[i][0]-a[i][1],ans+=a[i][1];
			sort(s+1,s+1+n,cmp1);
			for(int i=1;i<=n/2;i++)ans+=s[i]; 
			cout<<ans<<'\n';
			continue;
		}
		if(n<=400){
			//for(int i=1;i<=n;i++)cout<<a[i][0]<<' '<<a[i][1]<<' '<<a[i][2]<<'\n';
			int ans=0;
			for(int i=0;i<=n/2;i++)for(int j=0;j<=n/2;j++)f2[i][j]=INT_MIN;
			f2[0][0]=0;
			for(int i=1;i<=n;i++){
				for(int j=min(n/2,i);j>=0;j--){
					for(int k=min(n/2,i-j);k>=0;k--){
						int p=i-j-k;
						if(p>n/2||p<0)continue;
						if(p>=1)f2[j][k]=max(f2[j][k]+a[i][0],f2[j][k]);
						if(k>=1)f2[j][k]=max(f2[j][k],f2[j][k-1]+a[i][1]);
						if(j>=1)f2[j][k]=max(f2[j][k],f2[j-1][k]+a[i][2]);
						//cout<<j<<' '<<k<<' '<<p<<' '<<f2[j][k-1]<<' '<<f2[j-1][k]<<' '<<f2[j-1][k-1]<<'\n';
						ans=max(ans,f2[j][k]);
					}
				}
			}
			cout<<ans<<'\n';
		}
		
	}
	return 0;
} 
