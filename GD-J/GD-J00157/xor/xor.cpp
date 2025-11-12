#include<bits/stdc++.h>
using namespace std;
int a[500010];
struct ak{
	int l;
	int r;
}ac[1000010];
bool vis[1000010];
bool cmp(ak x,ak y){
	if(x.l!=y.l){
		return x.l<y.l;
	}
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n-i+1;++j){
			int num=0;
			for(int k=j;k<=j+i-1;++k){
				num^=a[k];
			}
			if(num==k){
				cnt++;
				ac[cnt].l=j;
				ac[cnt].r=j+i-1;
			}
		}
	}
	sort(ac+1,ac+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int ff=true;
		int left=ac[i].l,right=ac[i].r;
		for(int j=1;j<=cnt;j++){
			if(vis[i]==true){
				ff=false;
				break;
			}
			if(vis[j]){
				continue;
			}
			if(ac[j].l>=left&&ac[j].l<right&&ac[j].r<=right&&i!=j){
				ff=false;
				break;
			}if(ac[j].l>=right){
				break;
			}
		}
		if(ff==true){
			ans++;
			for(int j=1;j<=cnt;j++){
				if(ac[j].l>=left&&ac[j].l<=right&&i!=j){
					vis[j]=true;
				}
			}
		}else{
			vis[i]=true;	
		}
	}
	cout<<ans;
	return 0;
}//11:32 end score:60?
//final score:<=324
