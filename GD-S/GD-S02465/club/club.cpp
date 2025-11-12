#include<bits/stdc++.h>
using namespace std;
int n,t;
int c[3];
int p[100010],ans;
int a[100010][3];
int vec[100010],cnt;
int mn;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cin>>t;
	scanf("%d",&t);
	while(t--){
//		cin>>n;
		scanf("%d",&n);
		c[0]=c[1]=c[2]=0;
		ans=0;
//		vec.clear();
		cnt=0;
		for(int i=1;i<=n;i++){
//			cin>>a[i][0]>>a[i][1]>>a[i][2];
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int mx=max(a[i][0],max(a[i][1],a[i][2]));
			ans+=mx;
			if(a[i][0]==mx){
				p[i]=0;
			}else if(a[i][1]==mx){
				p[i]=1;
			}else{
				p[i]=2;
			}
//			cout<<p[i]<<",";
			c[p[i]]++;
		}
//		cout<<"\n";
		int id=-1;
		for(int i=0;i<=2;i++){
			if(c[i]>n/2){
				id=i;
				break;
			}
		}
//		cout<<"nowans::"<<ans<<"\n";
//		cout<<id<<"---";
		if(id==-1){
//			cout<<ans<<"\n";
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			if(p[i]==id){
				mn=200000;
				for(int j=0;j<=2;j++){
					if(j==id)continue;
					mn=min(mn,a[i][id]-a[i][j]);
				}
//				vec.push_back(mn);
				vec[++cnt]=mn;
//				cout<<"push "<<mn<<":"<<i<<"\n";
			}
		}
//		sort(vec.begin(),vec.end());
		sort(vec+1,vec+cnt+1);
		int val=c[id]-(n/2);
		for(int i=1;i<=val;i++)ans-=vec[i];
//		cout<<ans<<"\n";
		printf("%d\n",ans);
	}
	return 0;
}
