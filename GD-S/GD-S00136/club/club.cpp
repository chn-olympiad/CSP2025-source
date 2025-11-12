#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
int n,a[N][3],s[3],b[N],c[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	s[0]=s[1]=s[2]=0;
	ll res=0;
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			s[0]++,res+=a[i][0];
			b[i]=0;
		}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			s[1]++,res+=a[i][1];
			b[i]=1;
		}else{
			s[2]++,res+=a[i][2];
			b[i]=2;
		}
	}
	int k=-1;
	if(s[0]>n/2)k=0;
	else if(s[1]>n/2)k=1;
	else if(s[2]>n/2)k=2;
	if(k>=0){
		int idx=0;
		for(int i=1;i<=n;i++){
			if(b[i]==k){
				int x=a[i][k];
				for(int j=0;j<=2;j++)if(j!=k)x=min(x,a[i][k]-a[i][j]);
				c[++idx]=x;
			}
		}
		sort(c+1,c+idx+1);
		int w=n/2;
		for(int i=1;i<=s[k]-w;i++)res-=c[i];
	}
	cout<<res<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--)solve();
}

