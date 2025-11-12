#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long ans=0;
int flag[3];
struct node{
	int max1;
	int middle1;
	int cha;
	int maxid;
}a[N];
bool cmp(node x,node y){
	return x.cha<y.cha;
}
int main(){
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(flag,0,sizeof(flag));
		for(int i=1,q,w,e;i<=n;i++){
			cin>>q>>w>>e;
			if(q>=w&&q>=e){
				a[i].max1=q;
				flag[0]++;
				a[i].maxid=0;
				a[i].cha=q-max(w,e);
				if(w>e) a[i].middle1=w;
				else a[i].middle1=e;
			}
			else if(w>=q&&w>=e){
				a[i].max1=w;
				flag[1]++;
				a[i].maxid=1;
				a[i].cha=w-max(q,e);
				if(q>e) a[i].middle1=q;
				else a[i].middle1=e;
			}
			else if(e>=q&&e>=w){
				a[i].max1=e;
				flag[2]++;
				a[i].maxid=2;
				a[i].cha=e-max(w,q);
				if(q>w) a[i].middle1=q;
				else a[i].middle1=w;
			}
		}
		if(flag[0]<=n/2&&flag[1]<=n/2&&flag[2]<=n/2){
			for(int i=1;i<=n;i++){
				ans+=a[i].max1;
			}
		}
		else{
			if(flag[0]>n/2){
				int x1=flag[0]-n/2;
				sort(a+1,a+1+n,cmp);
				for(int i=1;i<=n;i++){
					if(a[i].maxid!=0){
						ans+=a[i].max1;
					}
					else if(x1>0){
						ans+=a[i].middle1;
						x1--;
					}
					else{
						ans+=a[i].max1;
					}
				}
			}
			else if(flag[1]>n/2){
				int x1=flag[1]-n/2;
				sort(a+1,a+1+n,cmp);
				for(int i=1;i<=n;i++){
					if(a[i].maxid!=1){
						ans+=a[i].max1;
					}
					else if(x1>0){
						ans+=a[i].middle1;
						x1--;
					}
					else{
						ans+=a[i].max1;
					}
				}
			}
			else{
				int x1=flag[2]-n/2;
				sort(a+1,a+1+n,cmp);
				for(int i=1;i<=n;i++){
					if(a[i].maxid!=2){
						ans+=a[i].max1;
					}
					else if(x1>0){
						ans+=a[i].middle1;
						x1--;
					}
					else{
						ans+=a[i].max1;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
