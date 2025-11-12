#include<bits/stdc++.h>
#define mm(a)	memset(a,0,sizeof(a))
using namespace std;
const int N=200003;
long long n,a[N],b[N],c[N],sa[N],sb[N],sc[N],ta,tb,tc;
int ans,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		mm(sa);
		mm(sb);
		mm(sc);
		ans=ta=tb=tc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				ans+=a[i];
				sa[++ta]=a[i]-max(b[i],c[i]);
			}else if(b[i]>c[i]&&b[i]>a[i]||b[i]==a[i]&&a[i]>c[i]){
				ans+=b[i];
				sb[++tb]=b[i]-max(a[i],c[i]);
			}else{
				ans+=c[i];
				sc[++tc]=c[i]-max(a[i],b[i]);
			}
		}
		if(ta>n/2){
			sort(sa+1,sa+ta+1);
			for(int i=1;ta-i>=n/2;i++)
			ans-=sa[i];
		}	
		if(tb*2>n){
			sort(sb+1,sb+tb+1);
			for(int i=1;(tb-i+1)*2>n;i++)
			ans-=sb[i];
		}
		if(tc*2>n){
			sort(sc+1,sc+tc+1);
			for(int i=1;(tc-i+1)*2>n;i++)
			ans-=sc[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

