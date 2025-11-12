#include <bits/stdc++.h>
using namespace std;
int tt,n,a[100010][5],cnt[5],d[100010],ans;
int pd(int x[5]){
	if(x[1]>x[2]&&x[1]>x[3]) return 1;
	if(x[2]>x[3]) return 2;
	return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tt;
	while(tt--){
		scanf("%d",&n);
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			cnt[pd(a[i])]++;
		}
		int k=pd(cnt);
		//cout<<k<<endl;
		for(int i=1;i<=n;i++){
			swap(a[i][1],a[i][k]);
			d[i]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
			ans+=a[i][1];
		}
		//cout<<ans<<endl;
		sort(d+1,d+n+1,greater<int>());
		//for(int i=1;i<=n;i++) cout<<d[i]<<' ';
		for(int i=1;i<=n;i++){
			if(i>n/2&&d[i]<0) break ;
			ans+=d[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}

