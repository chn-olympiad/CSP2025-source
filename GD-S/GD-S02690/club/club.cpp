#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int T,n,a[N],b[N],c[N],d[N],cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int sum1=0,sum2=0,sum3=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans+=a[i];
				sum1++;
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				ans+=b[i];
				sum2++;
			}else if(c[i]>=a[i]&&c[i]>=b[i]){
				ans+=c[i];
				sum3++;
			}
		}
		cnt=0;
		if(sum1>n/2){
			for(int i=1;i<=n;i++)if(a[i]>=b[i]&&a[i]>=c[i])d[++cnt]=max(b[i],c[i])-a[i];
			sort(d+1,d+cnt+1);
//			for(int i=1;i<=cnt;i++)cout<<d[i]<<" ";cout<<"\n";
			while(sum1>n/2){
				ans+=d[cnt];
				sum1--;cnt--;
			}
		}else if(sum2>n/2){
			for(int i=1;i<=n;i++)if(b[i]>=a[i]&&b[i]>=c[i])d[++cnt]=max(a[i],c[i])-b[i];
			sort(d+1,d+cnt+1);
//			for(int i=1;i<=cnt;i++)cout<<d[i]<<" ";cout<<"\n";
			while(sum2>n/2){
				ans+=d[cnt];
				sum2--;cnt--;
			}
		}else if(sum3>n/2){
			for(int i=1;i<=n;i++)if(c[i]>=a[i]&&c[i]>=b[i])d[++cnt]=max(a[i],b[i])-c[i];
			sort(d+1,d+cnt+1);
//			for(int i=1;i<=cnt;i++)cout<<d[i]<<" ";cout<<"\n";
			while(sum3>n/2){
				ans+=d[cnt];
				sum3--;cnt--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
