#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],cnt,cnt1,cnt0,cnto,prex[500005],ans,dis[500005],p;
struct e{
	vector<int>v;
}vv[500005];
void dfs(int l,int cnt){
	if(l>n){
		ans=max(ans,cnt);
		return;
	}
	for(int j=0;j<dis[l];j++){
		dfs(vv[l].v[j]+1,++cnt);
		cnt-=1;
	}
	return;
}
/*--------------------------------*/
signed main(){
	//freopen("xor1.in","r",stdin);
	//freopen("xor1.out","w",stdout);
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	p=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt1++;
		}else if(a[i]==0){
			cnt0++;
		}else{
			flag=false;
		}
		if(a[i]==1 && a[i-1]==1 && i>p+1){
			cnto++;
			p=i;
		}
		prex[i]=a[i]^prex[i-1];
	}
/*--------------------------------*/
	if(flag && k==0 && (!cnt1)){
		cout<<0;
		return 0;
	}else if(flag && (cnt0+cnto)){
		if(k==0){
			cout<<cnt0+cnto;
		}else{
			cout<<cnt1;
		}
		return 0;
	}else if(n<=1e3){
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				int x=prex[l-1]^prex[r];
				if(x==k){
					vv[l].v.push_back(r);
					dis[l]++;
				}
			}
		}
		dfs(1,0);
		cout<<ans;
		return 0;
	}
} 
