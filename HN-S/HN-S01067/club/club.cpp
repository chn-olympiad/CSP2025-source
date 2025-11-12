#include <bits/stdc++.h>
using namespace std;
struct P{
	int id;
	int v;
} p;
bool cmp(P x,P y)
{
	return x.v>=y.v;
}
int t;
bool use[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,ans=0,rest[4];
		vector < struct P >a[4];
		cin>>n;
		memset(use,0,sizeof(use));
		rest[1]=n/2;rest[2]=n/2;rest[3]=n/2;
		for(int i=1;i<=3;i++)a[i].push_back(p);
		for(int i=1;i<=n;i++){
			p.id=i;
			for(int j=1;j<=3;j++){
				scanf("%d",&p.v);
				a[j].push_back(p);
			}
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(a[2][i].v!=0){
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=3;i++){
			sort(a[i].begin()+1,a[i].end(),cmp);
		}
		for(int i=1;i<=n;i++){
			int mj=1,smj=1,last=1;
			for(int j=2;j<=3;j++){
				if(a[j][i].v>a[mj][i].v){
					mj=j;
				}
			}
			if(mj==1)smj=2;
			for(int j=1;j<=3;j++){
				if(j==mj)continue;
				if(a[j][i].v>a[smj][i].v){
					smj=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(j==mj || j==smj)continue;
				last=j;
			}
			if(use[a[mj][i].id]==false && rest[mj]>0){
				ans+=a[mj][i].v;
				rest[mj]--;
				use[a[mj][i].id]=true;
			}
			if(use[a[smj][i].id]==false && rest[smj]>0){
				ans+=a[smj][i].v;
				rest[smj]--;
				use[a[smj][i].id]=true;
			}
			if(use[a[last][i].id]==false && rest[last]>0){
				ans+=a[last][i].v;
				rest[last]--;
				use[a[last][i].id]=true;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
