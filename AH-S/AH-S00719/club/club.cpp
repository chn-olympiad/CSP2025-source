#include <bits/stdc++.h>
using namespace std;
struct m{
	int f1,f2,f3,max1,max2,min1,max1f,max2f,min1f;
};
bool cmp(m a,m b){
	if(a.max1!=b.max2)return a.max1>b.max1;
	if(a.max2!=b.max2)return a.max2>b.max2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;
		m a[100005];
		cin>>n;
		int num[4]={0,0,0,0};
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].f1>>a[i].f2>>a[i].f3;
			a[i].max1=max(max(a[i].f1,a[i].f2),a[i].f3);
			a[i].min1=min(min(a[i].f1,a[i].f2),a[i].f3);
			if(a[i].min1==a[i].f1&&a[i].max1==a[i].f2){a[i].max2=a[i].f3;a[i].max1f=2;a[i].min1f=1;a[i].max2f=3;}
			else if(a[i].min1==a[i].f2&&a[i].max1==a[i].f1){a[i].max2=a[i].f3;a[i].max1f=1;a[i].min1f=2;a[i].max2f=3;}                                             
			else if(a[i].min1==a[i].f1&&a[i].max1==a[i].f3){a[i].max2=a[i].f2;a[i].max1f=3;a[i].min1f=1;a[i].max2f=2;}
			else if(a[i].min1==a[i].f3&&a[i].max1==a[i].f1){a[i].max2=a[i].f2;a[i].max1f=1;a[i].min1f=3;a[i].max2f=2;}
			else if(a[i].min1==a[i].f2&&a[i].max1==a[i].f3){a[i].max2=a[i].f1;a[i].max1f=3;a[i].min1f=2;a[i].max2f=1;}
			else if(a[i].min1==a[i].f3&&a[i].max1==a[i].f2){a[i].max2=a[i].f1;a[i].max1f=2;a[i].min1f=3;a[i].max2f=1;}
		}sort(a+1,a+n+1,cmp);
		int numm[4]={0,0,0,0};
		int w=0;
		for(int i=1;i<=n;i++){
			numm[a[i].max1f]++;
			ans+=a[i].max1;
		}
		for(int i=1;i<=3;i++){
			if(numm[i]>n/2)w=1;
		}
		if(w==0)cout<<ans<<endl;
		else{
			ans=0;
			for(int i=1;i<=n;i++)ans+=a[i].max2;
			int f[100005];
			for(int i=1;i<=n;i++)f[i]=0;
			for(int i=n;i>=1;i--){
				for(int j=1;j<=n/2;j++){
					f[j]=max(f[j],f[j-1]+a[i].max1-a[i].max2);
				}
			}
			cout<<ans+f[n/2]<<endl;
		}
	}
	return 0;
}
