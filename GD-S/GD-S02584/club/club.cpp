#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
int t,n;
int a[N],b[N],c[N];
int ac[N],ab[N],bc[N],ans;
vector<pii>q,qq,qqq;
bool cmpa(pii x,pii y){
	if(ab[x.second]==ab[y.second]){
		return ac[x.second]>ac[y.second];
	}
	return ab[x.second]>ab[y.second];
}
bool cmpb(pii x,pii y){
	if(bc[x.second]==bc[y.second]){
		return -ab[x.second]>-ab[y.second];
	}
	return bc[x.second]>bc[y.second];
}
bool cmpc(pii x,pii y){
	if(-bc[x.second]==-bc[y.second]){
		return -ac[x.second]>-ac[y.second];
	}
	return -bc[x.second]>-bc[y.second];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		q.clear();
		qq.clear();
		qqq.clear();
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i]) q.push_back({a[i],i}),ans+=a[i];
			else if(b[i]>=a[i]&&b[i]>=c[i]) qq.push_back({b[i],i}),ans+=b[i];
			else qqq.push_back({c[i],i}),ans+=c[i];
			ac[i]=a[i]-c[i];
			ab[i]=a[i]-b[i];
			bc[i]=b[i]-c[i];
		}
		//printf("%d\n",ans);
		while(1){
			if(q.size()>n/2){
				//printf("a\n");
				sort(q.begin(),q.end(),cmpa);
				while(q.size()>n/2){
					pii tp=q[q.size()-1];
					if(qq.size()<n/2&&(ab[tp.second]<ac[tp.second]||qqq.size()>=n/2)){
						qq.push_back(tp);
						q.pop_back();
						ans-=ab[tp.second];
						//printf("a to b %d\n",ans);
					}else{
						qqq.push_back(tp);
						q.pop_back();
						ans-=ac[tp.second];
						//printf("a to c %d\n",ans);
					}
				}
			}
			else if(qq.size()>n/2){
				//printf("b\n");
				sort(qq.begin(),qq.end(),cmpb);
				while(qq.size()>n/2){
					pii tp=qq[qq.size()-1];
					if(qqq.size()<n/2&&(bc[tp.second]<-ab[tp.second]||q.size()>=n/2)){
						qqq.push_back(tp);
						qq.pop_back();
						ans-=bc[tp.second];
						//printf("b to c %d\n",ans);
					}else{
						q.push_back(tp);
						qq.pop_back();
						ans+=ab[tp.second];
						//printf("b to a %d %d %d\n",tp.first,tp.second,ans);
					}
				}
			}else if(qqq.size()>n/2){
				//printf("c\n");
				sort(qqq.begin(),qqq.end(),cmpc);
				while(qqq.size()>n/2){
					pii tp=qqq[qqq.size()-1];
					if(qq.size()<n/2&&(-bc[tp.second]<-ac[tp.second]||q.size()>=n/2)){
						qq.push_back(tp);
						qqq.pop_back();
						ans+=bc[tp.second];
						//printf("c to b %d\n",ans);
					}else{
						q.push_back(tp);
						qqq.pop_back();
						ans+=ac[tp.second];
						//printf("c to a %d\n",ans);
					}
				}
			}else{
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
