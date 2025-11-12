#include <bits/stdc++.h>
using namespace std;
int t,n;
struct people{
	int v[3],mx,mid,mn;
};bool cmp(people x,people y){
	if(x.mx-x.mid==y.mx-y.mid){
		if(x.mid-x.mn==y.mid-y.mn)return x.mx > y.mx;
		return x.mid-x.mn > y.mid-y.mn;
	}
	return x.mx-x.mid > y.mx-y.mid;
}
people a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	int val[3],cnt[3],vis[3];
	while(t--){
		scanf("%d",&n);
		for(int i = 1;i<=n;++i){
			scanf("%d%d%d",&a[i].v[0],&a[i].v[1],&a[i].v[2]);
			val[0]=a[i].v[0],val[1]=a[i].v[1],val[2]=a[i].v[2];
			sort(val,val+3);
			a[i].mx=val[2],a[i].mid=val[1],a[i].mn=val[0];
		}
		sort(a+1,a+n+1,cmp);
		/*for(int i = 1;i<=n;++i){
			cout<<a[i].v[0]<<' '<<a[i].v[1]<<' '<<a[i].v[2]<<' '<<a[i].mx<<"   ";
		}*/
		int ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i = 1;i<=n;++i){
			vis[0]=vis[1]=vis[2]=0;
			for(int j = 0;j<3;++j){
				if(a[i].mx==a[i].v[j]&&!vis[j]){
					vis[j]=1;
					if(cnt[j]<n/2){
						cnt[j]++,ans+=a[i].v[j];
					}else{
						for(int k = 0;k<3;++k){
							if(a[i].mid==a[i].v[k]&&!vis[k]){
								cnt[k]++,ans+=a[i].v[k];
								break;
							}
						}
					}
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
