#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N=1e5+10;
int n,ans,cnt[3];
struct node{
	int a[3],p1,p2;
}a[N];

bool cmp(node n1,node n2){
	return n1.p1!=n2.p1?n1.p1>n2.p1:n1.p2>n2.p2;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;++i){
			cin>>a[i].a[0]>>a[i].a[1]>>a[i].a[2];
			a[i].p1=max(a[i].a[0],max(a[i].a[1],a[i].a[2]))-(a[i].a[0]+a[i].a[1]+a[i].a[2]-max(max(a[i].a[0],a[i].a[1]),a[i].a[2])-min(min(a[i].a[0],a[i].a[1]),a[i].a[2]));
			a[i].p2=(a[i].a[0]+a[i].a[1]+a[i].a[2]-max(max(a[i].a[0],a[i].a[1]),a[i].a[2])-min(min(a[i].a[0],a[i].a[1]),a[i].a[2]))-min(min(a[i].a[0],a[i].a[1]),a[i].a[2]);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;++i){
			int ma=max(a[i].a[0],max(a[i].a[1],a[i].a[2])),mi=min(min(a[i].a[0],a[i].a[1]),a[i].a[2]),p=0,q=0,r=0;
			for(int j=0;j<3;++j){
				if(!p&&a[i].a[j]==ma){
					p=j;
					continue;
				}
				if(!q&&a[i].a[j]==mi){
					q=j;
					continue;
				}
				r=j;
			}
			if(cnt[p]<(int)n/2){
				ans+=a[i].a[p];
				cnt[p]++;
			}else if(cnt[r]<(int)n/2){
				ans+=a[i].a[r];
				cnt[r]++;
			}else{
				ans+=a[i].a[q];
				cnt[q]++;
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
