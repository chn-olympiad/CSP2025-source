#include<bits/stdc++.h>
#define int long long
using namespace std;
struct o{
	int a,b,c,id;
}k[200005];
bool cmp(o a,o b){
	return a.b-a.a>b.b-b.a;
}
bool cmp2(o a,o b){
	return a.c>b.c;
}
int pd[200005],a1,a2,a3,d[200005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	int yu=0;
	while(T--){
		// cout<<512*1024<<" ";
		a1=a2=a3=0;
		int n;
		cin>>n;
		// memset(pd,0,sizeof pd);
		// memset(k,0,sizeof k);
		// memset(d,0,sizeof d);
		for(int i=1;i<=n;i++)pd[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>k[i].a>>k[i].b>>k[i].c;
			k[i].id=i;
			if(k[i].a>=k[i].b&&k[i].a>=k[i].c){
				ans+=k[i].a;
				pd[i]=1;
				a1++;
			}
			else if(k[i].b>=k[i].a&&k[i].b>=k[i].c){
				ans+=k[i].b;
				pd[i]=2;
				a2++;
			}
			else ans+=k[i].c,pd[i]=3,a3++;
		}
		int tot=0;
		// cout<<a1<<" "<<a2<<" "<<a3<<" "<<a2+a1+a3<<" "<<n<<"\n";
		if(a1>n/2){
			for(int i=1;i<=n;i++){
				if(pd[i]==1){
					d[++tot]=max(k[i].b-k[i].a,k[i].c-k[i].a);
				}
			}
		}
		if(a2>n/2){
			for(int i=1;i<=n;i++){
				if(pd[i]==2){
					d[++tot]=max(k[i].c-k[i].b,k[i].a-k[i].b);
				}
			}
		}
		if(a3>n/2){
			for(int i=1;i<=n;i++){
				if(pd[i]==3){
					d[++tot]=max(k[i].b-k[i].c,k[i].a-k[i].c);
				}
			}
		}
		int len=max(0ll,max(a1-n/2,max(a2-n/2,a3-n/2)));
		sort(d+1,d+tot+1);
		for(int i=tot;i>=tot-len+1;i--)ans+=d[i];
		cout<<ans<<"\n";
	}
	return 0;
}