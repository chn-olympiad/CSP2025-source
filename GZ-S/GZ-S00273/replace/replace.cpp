//GZ-S00273
//¹óÑôÒ»ÖÐ Ñî¾ûº­
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans,pi[N],sz[N];
struct bbb{
	int xb,wy,bh;
}a[N];
string s[N][2],x,y,nx,ny;
bool flag=1;
bool cmp(bbb q,bbb p){
	return q.wy==p.wy?q.xb<p.xb:q.wy<p.wy;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		sz[i]=s[i][0].size();
		if(flag)
			for(int j=0;j<sz[i];j++)
				if(s[i][0][j]>'b' || s[i][1][j]>'b'){
					flag=0;
					break;
				}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			for(int j=0;j<sz[i];j++)
				if(s[i][0][j]=='b')	a[i].xb=j;
			for(int j=0;j<sz[i];j++)
				if(s[i][1][j]=='b')	a[i].wy=j-a[i].xb;
			a[i].bh=i;
		}
		sort(a+1,a+1+n,cmp);
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		bool flag2=1;
		int szx=x.size();
		int mn=-1,mx=-1;
		if(szx!=y.size()){
			cout<<0<<"\n";
			continue;
		}
		int xxxxb=0,yyyyb=0;
		for(int i=0;i<szx;i++){
			if(x[i]!=y[i]){
				if(mn==-1)	mn=i;
				mx=max(mx,i);
			}
			if(x[i]=='b')	xxxxb=i;
			if(y[i]=='b')	yyyyb=i;
			if(x[i]>'b' || y[i]>'b')	flag2=0;
		}
		if(flag2 && flag){
			int move=yyyyb-xxxxb;
			int l=1,r=n,rx=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid].wy<=move){
					rx=mid;
					l=mid+1;
				}
				else	r=mid-1;
			}
			for(int i=rx;a[i].wy==move && i<=n;i++){
				if(sz[a[i].bh]>szx || a[i].xb>xxxxb || sz[a[i].bh]-a[i].xb>szx-xxxxb)	continue;
				ans++;
			}
			cout<<ans<<"\n";
			continue;
		}
		int szz=mx-mx+1;
		for(int i=1;i<=n;i++){
			if(sz[i]>szx || sz[i]<szz)	continue;
			nx=s[i][0]+'#'+x;
			for(int j=1;j<=sz[i]+szx;j++){
				int k=pi[j-1];
				while(k>0 && nx[j]!=nx[k])	k=pi[k-1];
				if(nx[j]==nx[k])	k++;
				pi[j]=k;
				if(j>=sz[i]+1 && pi[j]==sz[i]){
					ny=x.substr(0,j-sz[i]-sz[i])+s[i][1]+x.substr(j-sz[i],szx-1);
					//cout<<i<<" "<<j<<" "<<res<<endl;
					if(ny==y)	ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

