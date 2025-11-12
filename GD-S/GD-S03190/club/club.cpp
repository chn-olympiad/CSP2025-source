#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int ans,k,maxn=-1;
bool b[100005];
int x[4],n;
void dfs(int a[100005][4],int p){
	if(p>n){
	if(ans>maxn)maxn=ans;
	return;
	
	}
	for(int i=1;i<=3;i++){
		if(x[i]>k or b[p]==1 ){
			continue;
		}
		else{
			/*if(k-x[1]>=n-p and k-x[2]>=n-p and k-x[3]>=n-p){
				if(a[p][i]<max(a[p][1],max(a[p][2],a[p][3])))continue;
			}*/
			x[i]++;
			ans+=a[p][i];
			b[p]=1;
			dfs(a,p+1);
			b[p]=0;
			ans-=a[p][i];
			x[i]--;
		}
	}
	b[p]=0;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		maxn=-1;
		x[1]=0;x[2]=0;x[3]=0;
		int a[100005][4];
		cin>>n;
		bool rp=1;
		ans=0;
		k=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0 or a[i][3]!=0)rp=0;
		}
		if(rp){
			int c[n+3];
			for(int i=1;i<=n;i++){
				c[i]=a[i][1];
				
			}
			sort(c+1,c+n+1);
			for(int i=n;i>n/2;i--){
				ans+=c[i];
			}
			cout<<ans<<endl;
			continue;
		}
		
		dfs(a,1);cout<<maxn<<endl; 
	}
	return 0;
} //dfs 20pts
