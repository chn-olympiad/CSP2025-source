#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[100005][3];
int q[100005];
int now[100005];
int sum[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		long long ans=0;
		cin>>n;
	//	cout<<n<<'\n';
		for(int i=1;i<=n;i++){
	//		cout<<i<<'\n';
			int maxd=0,maxn=-1;
			for(int j=0;j<3;j++){
				cin>>a[i][j];
	//			cout<<j<<'\n';
	//			cout<<a[i][j]<<'\n';
				if(a[i][j]>maxn){
					maxn=a[i][j];
					maxd=j;
				}
			}
			now[i]=maxd;
			sum[maxd]++;
			ans+=maxn;
		}
		int idx=-1;
		for(int i=0;i<3;i++){
			if(sum[i]>n/2){
				idx=i;
			}
		}
		if(idx!=-1){
			for(int i=1;i<=n;i++){
				q[i]=-1e5;
				if(now[i]!=idx) continue;
				for(int j=0;j<3;j++){
					if(now[i]!=j){
						q[i]=max(q[i],a[i][j]-a[i][now[i]]);
					}
				}
			}
			sort(q+1,q+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(sum[idx]<=n/2) continue;
				sum[idx]--;
				ans+=q[i];
			}
		}
		cout<<ans<<'\n';
		sum[0]=sum[1]=sum[2]=0;
	}
}
