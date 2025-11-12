#include<bits/stdc++.h>
using namespace std;
struct{
	int val;
	int ad;
}f[100010][10];
int t,n,a[100010],b[100010],c[100010];
int sum[10],mi[100010],mi2[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;x++){
		cin>>n;
		int summ=0,ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(mi,0,sizeof(mi));
		memset(mi,0,sizeof(mi2));
		memset(sum,0,sizeof(sum));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]){
				if(b[i]>=c[i]){
					f[i][1].ad=1,f[i][1].val=a[i];
					f[i][2].ad=2,f[i][2].val=b[i];
					mi[i]=a[i]-b[i];
				}
				else if(a[i]>=c[i]){
					f[i][1].ad=1,f[i][1].val=a[i];
					f[i][2].ad=3,f[i][2].val=c[i];
					mi[i]=a[i]-c[i];
				}
				else{
					f[i][1].ad=3,f[i][1].val=c[i];
					f[i][2].ad=1,f[i][2].val=a[i];
					mi[i]=c[i]-a[i];
				}
			}
			else{
				if(a[i]>=c[i]){
					f[i][1].ad=2,f[i][1].val=b[i];
					f[i][2].ad=1,f[i][2].val=a[i];
					mi[i]=b[i]-a[i];
				}
				else if(b[i]>=c[i]){
					f[i][1].ad=2,f[i][1].val=b[i];
					f[i][2].ad=3,f[i][2].val=c[i];
					mi[i]=b[i]-c[i];
				}
				else{
					f[i][1].ad=3,f[i][1].val=c[i];
					f[i][2].ad=2,f[i][2].val=b[i];
					mi[i]=c[i]-b[i];
				}
			}
		}
		for(int i=1;i<=n;i++) sum[f[i][1].ad]++;
		for(int i=1;i<=3;i++){
			if(sum[i]>n/2){
				int temp=0;
				for(int j=1;j<=n;j++) if(f[j][1].ad==i) mi2[++temp]=mi[j];
				sort(mi2+1,mi2+temp+1);
				for(int j=1;j<=sum[i]-n/2;j++) summ+=mi2[j];
			}
		} 
		for(int i=1;i<=n;i++) ans+=f[i][1].val;
		cout<<ans-summ<<endl;
	}
	return 0;
} 
