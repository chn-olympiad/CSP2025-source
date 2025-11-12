#include<bits/stdc++.h>//y
using namespace std;
#define ll long long
#define vv vector
int a[100005][3],x[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
	int ans=0;
		int z=0,w=0,k=0,n;
		int mn=1e9,h=0;
		cin>>n;
		int l=n/2;
		vv<int> q(n+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				q[i]=max(a[i][j],q[i]);
				if(a[i][j]==q[i])x[i]=j;
			}
		}
	vv<bool> zz(n+1),ww(n+1),kk(n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[i]==1&&x[j]==1&&!zz[i]){
					zz[j]=true;
					z++;
					continue;
				}
				if(x[i]==2&&x[j]==2&&!ww[i]){
					ww[j]=true;
					w++;
					continue;
				}
				if(x[i]==3&&x[j]==3&&!kk[i]){
					kk[j]=true;
					k++;
					continue;
				}
			}
		}
		w++;
		k++;
		z++;
		if(z<=l&&w<=l&&k<=l){
			for(auto& qs:q)ans=ans+qs;
			cout<<ans<<"\n";
		}else{
			for(int i=0;i<=n;i++){
				if(z>l){
					if(x[i]==1){
						mn=min(a[i][1],mn);
						if(a[i][1]==mn)a[i][1]=50;
						z--;
					}
					q[i]=*min_element(a[i]+1,a[i]+4);
				}
				else if(w>l){
					if(x[i]==2){
						mn=min(a[i][2],mn);
						if(a[i][2]==mn)a[i][2]=50;
						w--;
					}
					q[i]=*min_element(a[i]+1,a[i]+4);
				}
				else if(k>l){
					if(x[i]==3){
						mn=min(a[i][3],mn);
						if(a[i][3]==mn)a[i][3]=50;
						k--;
					}
					q[i]=*min_element(a[i]+1,a[i]+4);
				}
				else break;
			}
			for(int i=1;i<=n;i++)ans+=q[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}
