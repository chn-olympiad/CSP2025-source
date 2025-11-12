#include<bits/stdc++.h>
#define num first
#define id second
using namespace std;
pair<long long,int>a[210000];
pair<long long,int>b[210000];
int t;
int vis[210000];
bool cmp(pair<long long,int> x,pair<long long,int> y){return x.num>y.num;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;cin>>n;
		long long sum=0;
		for(int i=1;i<=n;i++){
			long long x,y,z;cin>>x>>y>>z;
			sum+=x;
			a[i].num=y-x;b[i].num=z-x;
			a[i].id=b[i].id=i;vis[i]=0;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		int cnta=0,cntb=0;
		for(int i=1,j=1;i<=n&&j<=n;){
			while(vis[a[i].id])i++;
			while(vis[b[j].id])j++;
			if(a[i].num<0&&b[j].num<0&&cnta+cntb>=n/2)break;
			if(cnta==n/2){
				while(b[j].num>0&&cntb<n/2){
					if(vis[b[j].id])j++;
					else sum+=b[j].num,j++,cntb++;
				}
				break;
			}
			if(cntb==n/2){
				while(a[i].num>0&&cnta<n/2){
					if(vis[a[i].id])i++;
					else sum+=a[i].num,i++,cnta++;
				}
				break;
			}
			if(a[i].num>0&&b[j].num>0&&vis[a[i].id]!=vis[b[j].id]){
				sum+=a[i].num;vis[a[i].id]=1;cnta++;i++;
				sum+=b[j].num;vis[b[j].id]=1;cntb++;j++;
			}
			else if(a[i].num>b[j].num){
				sum+=a[i].num;vis[a[i].id]=1;cnta++;i++;
			}else{
				sum+=b[j].num;vis[b[j].id]=1;cntb++;j++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
} 
