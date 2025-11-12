#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//不开ll见祖宗
int T,n,c[100005],cnt[5],idx;
struct nd{
	int	id,b[5];
}a[100005],d[100005];
bool cmp2(nd x,nd y){
	ll mx=0,my=0,mix=0,miy=0;
	for(int j=1;j<=3;j++){
		if(j==idx)continue;
		mx=max(mx,0ll+x.b[j]);
	}
	for(int j=1;j<=3;j++){
		if(j==idx)continue;
		my=max(my,0ll+y.b[j]);
	}
	mix=x.b[idx]-mx,miy=y.b[idx]-my;
	if(mix!=miy)return mix<miy;
	return x.id<y.id;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);//freopen注释最后删掉，测了大样例改成正确格式就不要动了 
	cin>>T;
	while(T--){
		cin>>n;
		ll ans=0;
		for(int i=1;i<=n;++i)c[i]=0;//每个数选哪个社团
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;++i){
			int tmpm=0,tmpi=0;
			a[i].id=i;
			for(int j=1;j<=3;j++){
				cin>>a[i].b[j];
				if(a[i].b[j]>=tmpm)tmpm=a[i].b[j],tmpi=j;//选择最大的那个
			}
			cnt[tmpi]++,c[i]=tmpi;
		}
		int m=n/2;
		if(cnt[1]<=m&&cnt[2]<=m&&cnt[3]<=m){//如果不需要匀
			for(int i=1;i<=n;i++)ans+=a[i].b[c[i]];
		}
		else{
			idx=0;
			for(int i=1;i<=3;i++){
				if(cnt[i]>m)idx=i;
			}
			int tot=0;
			for(int i=1;i<=n;i++){
				if(c[i]==idx)d[++tot]=a[i];
			}
			sort(d+1,d+1+tot,cmp2);
			for(int i=1;i<=tot-m;i++){
				ll ma=0;
				for(int j=1;j<=3;j++){
					if(j==idx)continue;
					if(d[i].b[j]>=ma)ma=d[i].b[j],c[d[i].id]=j;
				}
			}
			for(int i=1;i<=n;i++)ans+=a[i].b[c[i]];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
