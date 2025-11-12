#include<bits/stdc++.h>
using namespace std;
const int N=5555,mod=998244353;
int a[N],cnt=0,n,vst[N],anss[N];
long long ans=0,ans1=0;
long long zhs(int nn,int mm){
	long long sum=0,a=nn,b=mm,c=nn-mm,jca=1,jcb=1;
	for(int i=max(nn-mm,mm)+1;i<=nn;i++){
		//cout<<i<<'\n';
		jca*=i;
		jca%=mod;
	}
	for(int i=1;i<=min(mm,nn-mm);i++){
		jcb*=i;
		jcb%=mod;
	}
	//cout<<jca<<' '<<jcb<<'\n';
	sum=jca/jcb;
	return max(1ll*1,sum);
}
void dfs(int step,int pos){
	if(step==0){
		int maxx=-1,sum=0;
		for(int i=1;i<=cnt;i++){
			sum+=anss[i];
			maxx=max(maxx,anss[i]);
		}	
		if(sum>maxx*2) ans++;
		ans%=mod;
		return;
	}
	for(int i=pos;i<=n;i++){
		if(vst[i]==0){
			vst[i]=1;
			cnt++;
			anss[cnt]=a[i];
			dfs(step-1,i+1);
			cnt--;
			vst[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	bool bf=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]!=1) bf=0;
	}
	if(bf==1){
		for(int i=3;i<=n;i++){
			ans+=zhs(n,i);
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		for(int i=3;i<=n;i++){
			cnt=0;
			dfs(i,1);
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}
