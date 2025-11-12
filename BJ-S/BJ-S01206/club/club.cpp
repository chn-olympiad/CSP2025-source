#include<bits/stdc++.h>
using namespace std;
int sum[5],a[100005][5],m[100005];
struct node{
	int n;
	int i;
	int m;
} di[100005];
bool cmp(node a,node b){
	return a.n<b.n;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		sum[1]=sum[2]=sum[3]=0;
		int n;
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				m[i]=1;
				di[i].m=1;
				sum[1]++;
				di[i].n=a[i][1]-max(a[i][2],a[i][3]);
			} else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				m[i]=2;
				di[i].m=2;
				di[i].n=a[i][2]-max(a[i][1],a[i][3]);
				sum[2]++;
			} else	if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				m[i]=3;
				di[i].m=3;
				di[i].n=a[i][3]-max(a[i][2],a[i][1]);
				sum[3]++;
			}
			di[i].i=i;
			//cout<<m[i]<<endl;
		}
		int maxn=-1,maxi;
		for(int i=1; i<=3; i++){
			if(maxn<=sum[i]){
				maxn=sum[i];
				maxi=i;
			}
		}
		//cout<<maxn<<endl;
		if(maxn>n/2){
			sort(di+1,di+n+1,cmp);
			for(int i=1; i<=n; i++){
				if(di[i].m==maxi){
					int tmp=-1,maxp;
					for(int j=1; j<=3; j++){
						if(a[di[i].i][j]>=tmp&&maxi!=j){
							maxp=j;
							tmp=a[di[i].i][j];
						}
					}
					m[di[i].i]=maxp;
					maxn--;
				}
				if(maxn<=n/2) break;
			}
		}
		int ans=0;
		for(int i=1; i<=n; i++){
			ans+=a[i][m[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
}