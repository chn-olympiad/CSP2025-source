#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define N 100010
int T,n,a[N][4],op[N],bk[10],b[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;rep(i,1,n){cin>>a[i][1]>>a[i][2]>>a[i][3];}
		bk[1]=bk[2]=bk[3]=0;int s=0;
		rep(i,1,n){
			s+=max(max(a[i][1],a[i][2]),a[i][3]);
			if(a[i][1]==max(max(a[i][1],a[i][2]),a[i][3])){op[i]=1;bk[1]++;continue;}
			if(a[i][2]==max(max(a[i][1],a[i][2]),a[i][3])){op[i]=2;bk[2]++;continue;}
			if(a[i][3]==max(max(a[i][1],a[i][2]),a[i][3])){op[i]=3;bk[3]++;continue;}
		}
		int id=0;if(bk[1]>n/2){id=1;}if(bk[2]>n/2){id=2;}if(bk[3]>n/2){id=3;}
		if(!id){cout<<s<<'\n';continue;}
		int nums=bk[id]-n/2;
		rep(i,1,n){
			if(op[i]!=id){b[i]=1e16;continue;}
			int sec=a[i][1]+a[i][2]+a[i][3]-max(max(a[i][1],a[i][2]),a[i][3])-min(min(a[i][1],a[i][2]),a[i][3]);
			b[i]=max(max(a[i][1],a[i][2]),a[i][3])-sec;
		}
		sort(b+1,b+n+1);rep(i,1,nums){s-=b[i];}cout<<s<<'\n';
	}
	return 0;
} 
