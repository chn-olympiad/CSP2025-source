#include<bits/stdc++.h>
using namespace std;
struct peo{
	long long ma;
	long long mb;
	long long mc;
	long long maxx;
	long long maxn;
	long long wz;
};
peo a[100005];
long long q[100005];
long long na[10005];
long long nb[10005];
long long nc[10005];
long long ans[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int ta=t;
	while(t--){
		int n;
		int p=0;
		int ga=1;
		int gb=1;
		int gc=1;
		int k=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].ma>>a[i].mb>>a[i].mc;
			a[i].maxx=max(a[i].ma,a[i].mb);
			a[i].maxn=max(min(a[i].ma,a[i].mb),a[i].mc);
			a[i].maxx=max(a[i].maxx,a[i].mc);
			if(a[i].maxx==a[i].ma){
				a[i].wz=1;
				na[ga]=a[i].maxn;
				ga++;
			}
			if(a[i].maxx==a[i].mb){
				a[i].wz=2;
				nb[gb]=a[i].maxn;
				gb++;
			}
			if(a[i].maxx==a[i].mc){
				a[i].wz=3;
				nc[gc]=a[i].maxn;
				gc++;
			}
		}
		for(int i=1;i<=n;i++){
			q[a[i].wz]++;
		}
		sort(na,na+ga+1);
		sort(nb,nb+gb+1);
		sort(nc,nc+gc+1);
		for(int i=1;i<=3;i++){
			if(q[i]<=n/2){
				for(int j=1;j<=n;j++){
					if(a[j].wz==i and q[i]>0){
						p=p+a[j].maxx;
						q[i]--;
					}
				}
			}
			if(q[i]>=n/2){
				k=q[i]-(n/2);
				for(int j=1;j<=k;j++){
					if(i==1){
						p=p+na[4-j];
					}
					if(i==2){
						p=p+nb[4-j];
					}
					if(i==3){
						p=p+nc[4-j];
					}
				}
				for(int j=k+1;j<=n;j++){
					p=p+a[j].maxx;
				}
			}
		}
		ans[ta-t]=p;
		p=0;
	}
	for(int i=1;i<=ta;i++){
		cout<<ans[i];
		if(i!=ta){
			cout<<endl;
		}
	}
	return 0;
}