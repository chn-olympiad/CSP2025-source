#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int T,n,a[N][4],st1[N],k[N],ans,p[N];
struct shetuan{
	int z,st,r;
}m1[N],m2[N],m3[N];
bool cmp(shetuan x,shetuan y){
	return x.z<y.z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int num=0,ans=0;
		memset(k,0,sizeof(k));
		cin>>n;
		for(int i=1;i<=n;i++){
			m1[i].r=i;m2[i].r=i;m3[i].r=i;
			memset(st1,0,sizeof(st1));
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			st1[a[i][1]]=1;st1[a[i][2]]=2;st1[a[i][3]]=3;
			sort(a[i]+1,a[i]+4);
			m1[i].z=a[i][3];m2[i].z=a[i][2];m3[i].z=a[i][1];
			m1[i].st=st1[a[i][3]];
			m2[i].st=st1[a[i][2]];
			m3[i].st=st1[a[i][1]];
		}
		sort(m1+1,m1+1+n,cmp);
		sort(m2+1,m2+1+n,cmp);
		sort(m3+1,m3+1+n,cmp);
		if(n==2){
			cout<<max(a[1][3]+a[2][2],a[1][2]+a[2][3])<<'\n';
			continue;
		}
		//for(int i=n;i>=1;i--)cout<<m1[i].z<<' '<<m2[i].z<<' '<<m3[i].z<<'\n';
		for(int i=n;i>=1;i--){
			int k1=m1[i].st;
			if(k[k1]<n/2){
				ans+=m1[i].z;
				k[k1]++;
				num++;
			}
			p[m1[i].r]=1;
		}
		if(num<n){
			for(int i=n;i>=1;i--){
				if(p[m2[i].r]==1)break;
				int k1=m2[i].st;
				if(k[k1]<n/2){
					ans+=m2[i].z;
					k[k1]++;
					num++;
				}
				p[m2[i].r]=1;
			}
			if(num<n){
				for(int i=1;i<=n;i++){
					if(p[m3[i].r]==1)break;
					int k1=m3[i].st;
					if(k[k1]<n/2){
						ans+=m3[i].z;
						k[k1]++;
						num++;
					}
					p[m3[i].r]=1;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
