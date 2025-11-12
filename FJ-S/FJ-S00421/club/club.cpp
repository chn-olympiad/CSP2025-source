#include <bits/stdc++.h>
using namespace std;
struct str{
	int p,l,r;
}a[300050];
int t,n,ans,v[100010][3]; 
bool cmp(str u,str v){
	return u.p>v.p;
}
void dfs(int x,int w1,int w2,int w3,int sum){
	if(x==n){
		ans=max(ans,sum);
		return;
	}
	if(w1<n/2) dfs(x+1,w1+1,w2,w3,sum+v[x+1][1]);
	if(w2<n/2) dfs(x+1,w1,w2+1,w3,sum+v[x+1][2]);
	if(w3<n/2) dfs(x+1,w1,w2,w3+1,sum+v[x+1][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		if(n<=10){
			for(int i=1;i<=n;i++){
				cin>>v[i][1]>>v[i][2]>>v[i][3];
			}
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}else{
			int b[100010]={0},k=0,w[4]={0};
			for(int i=1;i<=n;i++){
				cin>>a[++k].p;
				a[k].l=i,a[k].r=1;
				cin>>a[++k].p;
				a[k].l=i,a[k].r=2;
				cin>>a[++k].p;
				a[k].l=i,a[k].r=3;
			}
			sort(a+1,a+3*n+1,cmp);
			for(int i=1;i<=3*n;i++){
				if(b[a[i].l]==0&&w[a[i].r]<n/2){
					b[a[i].l]=1;
					w[a[i].r]++;
					ans+=a[i].p;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}


