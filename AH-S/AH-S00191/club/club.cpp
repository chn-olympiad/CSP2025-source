#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,a[100010][4],sum,vis=-1,s[4],cha[100010];
int n;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	while(m--){
		cin>>n;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=2;j++) cin>>a[i][j];
			int minn=min(a[i][0],min(a[i][1],a[i][2])),maxn=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][0]==maxn){
				if(a[i][1]==minn){
					s[0]++;
					cha[i]=a[i][0]-a[i][2];
					sum+=a[i][0];
				}else{
					s[0]++;
					cha[i]=a[i][0]-a[i][1];
					sum+=a[i][0];
				}
			}else if(a[i][1]==maxn){
				if(a[i][0]==minn){
					s[1]++;
					cha[i]=a[i][1]-a[i][2];
					sum+=a[i][1];
				}else{
					s[1]++;
					cha[i]=a[i][1]-a[i][0];
					sum+=a[i][1];
				}
			}else{
				if(a[i][1]==minn){
					s[2]++;
					cha[i]=a[i][2]-a[i][0];
					sum+=a[i][2];
				}else{
					s[2]++;
					cha[i]=a[i][2]-a[i][1];
					sum+=a[i][2];
				}
			}
		}int mid=n/2;
		for(int i=0;i<=2;i++) if(s[i]>mid){
			vis=i;
			break;
		}if(vis!=-1){
			for(int i=1;i<=n;i++){
				if(a[i][vis]==max(a[i][0],max(a[i][1],a[i][2]))) cha[i]=2*max(a[i][0],max(a[i][1],a[i][2]))-(a[i][0]+a[i][1]+a[i][2])+min(a[i][0],min(a[i][1],a[i][2]));
				else cha[i]=2147483646;
			}sort(cha+1,cha+n+1);
			for(int i=n/2+1;i<=s[vis];i++){
				sum-=cha[i-n/2];
			}
		}cout<<sum<<endl;
		sum=0;
		memset(s,0,sizeof(s));
		memset(cha,0,sizeof(cha));
		vis=-1;
	}return 0;
}
