#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define x first
#define y second
#define vt vector
#define pb push_back
using namespace std;
const int N=1e6+10;
const int M=1e3+10;
const int INF=0x3f3f3f3f;
ll n,k,a[N],sum[N],ans,unl=INF,unr,xx,c[N],cnt1,cnt2;
bool vis[N];
PII b[N];
bool cmp(PII aa,PII bb){
	return (aa.y-aa.x+1)<(bb.y-bb.x+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)cnt1++;
		if(a[i]==1)cnt2++;
		sum[i]=sum[i-1]^a[i];
	}
	if(cnt1+cnt2==n){
		if(k==0){
			cout<<cnt1;
			return 0;
		}else if(k==1){
			cout<<cnt2;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
//				cout<<i<<" "<<j<<endl; 
				b[++xx].x=i,b[xx].y=j;
				c[xx]=j-i+1;
//				if((i<unl&&j<unl)||(i>unr&&j>unr)){
//					unl=max(unl,(ll)i);
//					unr=max(unr,(ll)j);
//					ans++;
//				}
			}
		}
	}
//	sort(b+1,b+xx+1,cmp);
	for(int i=1;i<=xx;i++){
		for(int j=i+1;j<=xx;j++){
			if(c[i]>c[j]){
				swap(c[i],c[j]);
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=1;i<=xx;i++){
//		cout<<b[i].x<<" "<<b[i].y<<" "<<c[i]<<endl;
		bool flag=1;
		for(int j=b[i].x;j<=b[i].y;j++){
			if(vis[j]){
				flag=0;
			}
		}
		if(flag){
			ans++;
			for(int j=b[i].x;j<=b[i].y;j++){
				vis[j]=1;
			}
//			cout<<b[i].x<<" "<<b[i].y<<" "<<c[i]<<endl;
		}
	}
	cout<<ans;
	return 0;
}

