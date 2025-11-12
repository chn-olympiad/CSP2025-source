#include<bits/stdc++.h>
using namespace std;

int t,n;
const int N=100005;
int a[N][4];

int f[N][4],a1[N];

bool cmp(int x,int y){
	return x>y;
}
vector<int> cnt[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool f=1,q=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j>1&&a[i][j]!=0) f=0;
			}
			if(a[i][3]!=0) q=0;
			a1[i]=a[i][1];
		}if(n==2){
			int ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j) ans=max(ans,a[1][i]+a[2][j]);
				}
			}
			cout<<ans;
			continue;
		}
		if(f){
			int ans=0;
			sort(a1+1,a1+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a1[i];
			cout<<ans;
			continue;
		}
		if(q){
			int ans=0;
			cnt[1].clear();
			cnt[2].clear();
			for(int i=1;i<=n;i++){
				if(cnt[2].size()==n/2){
					int sum=0,op;
					for(int j=0;j<cnt[2].size();j++){
						int id=cnt[2][j];
						if(ans+a[id][1]-a[id][2]+a[i][2]>sum){
							sum=ans+a[id][1]-a[id][2]+a[i][2];
							op=j;
						}
					}
					if(ans+a[i][1]<sum){
						ans=sum;
						cnt[2][op]=i;
						cnt[1].push_back(op);
					}
					else{
						ans+=a[i][1];
						cnt[1].push_back(i);
					}
				}
				else if(cnt[1].size()==n/2){
					int sum=0,op;
					for(int j=0;j<cnt[1].size();j++){
						int id=cnt[1][j];
						if(ans+a[id][2]-a[id][1]+a[i][1]>sum){
							sum=ans+a[id][2]-a[id][1]+a[i][1];
							op=j;
						}
					}
					if(ans+a[i][2]<sum){
						ans=sum;
						cnt[1][op]=i;
						cnt[2].push_back(op);
					}
					else{
						ans+=a[i][1];
						cnt[1].push_back(i);
					}
				}
				else{
					if(a[i][1]<a[i][2]){
						ans+=a[i][2];
						cnt[2].push_back(i);
					}
					else{
						ans+=a[i][1];
						cnt[1].push_back(i);
					}
				}
			}
			cout<<ans;
			continue;
		}
		
		
	} 
	return 0;
}
