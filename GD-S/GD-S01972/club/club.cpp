#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long  t,n,a[N][4],ans,k[N],vc1[N],vc2[N],vc3[N],cnt[4];
int fmx(int i){
	if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) return 1;
	if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) return 2;
	return 3;
}
long long fml(int x,int i){
	int mx;
	if(x==1){
	    mx=max(a[i][2],a[i][3]);
		return a[i][1]-mx;	
	}
	if(x==2){
	    mx=max(a[i][1],a[i][3]);
		return a[i][2]-mx;	
	}
	mx=max(a[i][1],a[i][2]);
	return a[i][3]-mx;
}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	    cin>>n;
	    ans=0;
		memset(a,0,sizeof a);
		memset(k,0,sizeof k);
		memset(cnt,0,sizeof cnt);
		memset(vc1,0,sizeof vc1);
		memset(vc2,0,sizeof vc2);
		memset(vc3,0,sizeof vc3);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++){
		int x=fmx(i);
		k[i]=fml(x,i);
		cnt[x]++;
		ans+=a[i][x];
		if(x==1) vc1[cnt[x]]=k[i];
		if(x==2) vc2[cnt[x]]=k[i];
		if(x==3) vc3[cnt[x]]=k[i];
	}
	sort(vc1+1,vc1+1+cnt[1]);
	sort(vc2+1,vc2+1+cnt[2]);
	sort(vc3+1,vc3+1+cnt[3]);
	for(int i=1;i<=3;i++){
		if(cnt[i]>n/2){
		    if(i==1){
		    	for(int j=1;j<=cnt[i]-n/2;j++) ans-=vc1[j];
		    	break;
			}
			if(i==2){
		    	for(int j=1;j<=cnt[i]-n/2;j++) ans-=vc2[j];
		    	break;
			}
			if(i==3){
		    	for(int j=1;j<=cnt[i]-n/2;j++) ans-=vc3[j];
		    	break;
			}
				
		}
	}
	cout<<ans<<endl;	
	}
	return 0;
} 
