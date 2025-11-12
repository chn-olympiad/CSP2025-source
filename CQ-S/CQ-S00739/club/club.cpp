#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,c1[N],c2[N],c3[N],x[N],y[N],z[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int s1=0,s2=0,s3=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			if(x[i]>=y[i]&&x[i]>=z[i]){
				s1+=x[i];
			}
			else if(x[i]<=y[i]&&y[i]>=z[i]){
				s2+=y[i];
			}
			else if(z[i]>=x[i]&&z[i]>=y[i]){
				s3+=z[i];
			}
		}
		ans=s1+s2+s3;
		cout<<ans<<"\n";
	}
	return 0;
}
