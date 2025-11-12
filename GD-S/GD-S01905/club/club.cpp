#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+5;

long long n,a[5][N],id[5][N],ll[5],sum[N],ans;

void clean(){
	memset(a,0,sizeof(a));
	memset(id,0,sizeof(id));
	memset(ll,0,sizeof(ll));
	memset(sum,0,sizeof(sum));
	n=ans=0;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[1][i]>>a[2][i]>>a[3][i],swap(a[1][i],a[2][i]);
	for(int i=1;i<=n;i++){
		int ma=max(a[1][i],max(a[2][i],a[3][i]));
		ans+=ma;
		if(a[1][i]==ma) id[1][++ll[1]]=i;
		else if(a[2][i]==ma) id[2][++ll[2]]=i;
		else id[3][++ll[3]]=i; 
	}
	int ma=max(ll[1],max(ll[2],ll[3]));
	if(ma<=n/2){
		cout<<ans<<"\n";
		return;
	}
	if(ll[1]==ma){
		for(int i=1;i<=ll[1];i++) sum[i]=a[1][id[1][i]]-max(a[2][id[1][i]],a[3][id[1][i]]);
		sort(sum+1,sum+ll[1]+1);
		for(int i=1;i<=ll[1]-n/2;i++) ans-=sum[i];
	}
	else if(ll[2]==ma){
		for(int i=1;i<=ll[2];i++) sum[i]=a[2][id[2][i]]-max(a[1][id[2][i]],a[3][id[2][i]]);
		sort(sum+1,sum+ll[2]+1);
		for(int i=1;i<=ll[2]-n/2;i++) ans-=sum[i];
	}
	else{
		for(int i=1;i<=ll[3];i++) sum[i]=a[3][id[3][i]]-max(a[1][id[3][i]],a[2][id[3][i]]);
		sort(sum+1,sum+ll[3]+1);
		for(int i=1;i<=ll[3]-n/2;i++) ans-=sum[i];
	}
	cout<<ans<<"\n";
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve(),clean();
}
