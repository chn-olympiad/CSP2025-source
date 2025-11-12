#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct _{
	int a[4],mx,vx,vy,im,ix,iy;
	
}s[N];
int n;
int cnt[4],k;
bool vis[N];
int res=0;
bool cmp(_ A,_ B){
	return A.mx-A.vx<B.mx-B.vx;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n;res=0;
		memset(cnt,0,sizeof cnt);
		memset(vis,0,sizeof vis);//important
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&s[i].a[1],&s[i].a[2],&s[i].a[3]);
			
			s[i].mx=s[i].a[1];
			s[i].vx=s[i].a[2];
			s[i].vy=s[i].a[3];
			s[i].im=1;
			s[i].ix=2;
			s[i].iy=3;
			if(s[i].mx<s[i].vx){
				swap(s[i].mx,s[i].vx);
				swap(s[i].im,s[i].ix);
			}
			if(s[i].mx<s[i].vy){
				swap(s[i].mx,s[i].vy);
				swap(s[i].im,s[i].iy);
			}
			if(s[i].vx<s[i].vy){
				swap(s[i].vx,s[i].vy);
				swap(s[i].ix,s[i].iy);
			}
//			s[i].vy=s[i].vx-s[i].vy;
//			s[i].vx=s[i].mx-s[i].vx;
			
			res+=s[i].mx;
			cnt[s[i].im]++;
//			printf("%lld %lld %lld\n",s[i].mx,s[i].vx,s[i].vy);
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			cout<<res<<"\n";
			continue;
		}
		else{
			k=0;
//			cout<<res<<"\n";
			while(cnt[++k]<=n/2);
//			cout<<k<<"\n";
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(!vis[i]&&s[i].im==k){
					vis[i]=1;
//					cout<<i<<"\n";
					cnt[k]--;
					res=res-s[i].mx+s[i].vx;
//					cout<<s[i].mx+s[i].vx<<"\n";
					if(cnt[k]<=n/2){
						break;
					}
					cnt[s[i].ix]++;
				}
//				printf("%lld %lld %lld\n",s[i].mx,s[i].vx,s[i].vy);
//				cout<<s[i].vx<<"\n";
			}
			cout<<res<<"\n";
		}
	}
	return 0;
} 
