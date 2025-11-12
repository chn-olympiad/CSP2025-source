#include<bits/stdc++.h>
#define int long long
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N=1e5+10;
int T,n;
int a[N],b[N],c[N],d[N],ans;
int s1,s2,s3;
int ta[N],tb[N],tc[N],t1,t2,t3;
signed main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;t1=t2=t3=0;ans=0;s1=s2=s3=0;
		forr(i,1,n)cin>>a[i]>>b[i]>>c[i];
		forr(i,1,n){
			int mx=max(a[i],max(b[i],c[i]));
			if(mx==a[i]){
				s1++;
				ans+=a[i];
				ta[++t1]=a[i]-max(b[i],c[i]);
			}else if(mx==b[i]){
				s2++;
				ans+=b[i];
				tb[++t2]=b[i]-max(a[i],c[i]);
			}else {
				s3++;
				ans+=c[i];
				tc[++t3]=c[i]-max(a[i],b[i]);
			}
		}
		if(s1<=n/2&&s2<=n/2&&s3<=n/2){
			cout<<ans<<endl;continue;
		}
		if(s1>n/2){
			sort(ta+1,ta+1+t1);
			forr(i,1,s1-n/2)ans-=ta[i];
		}else if(s2>n/2){
			sort(tb+1,tb+1+t2);
			forr(i,1,s2-n/2)ans-=tb[i];
		}else{
			sort(tc+1,tc+1+t3);
			forr(i,1,s3-n/2)ans-=tc[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
