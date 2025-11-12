#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define vt vector
#define pb push_back
using namespace std;
const int N=1e6+10;
const int M=1e3+10;
const int INF=0x3f3f3f3f;
ll n,m,a[N],xx,ans[M][M],idx=1,idy=1,cnt;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)xx=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		ans[idx][idy]=a[i];
//		cout<<idx<<" "<<idy<<endl;
		if(idx==n&&cnt==0){
			idy++;
			cnt=1;
			continue;
		}
		if(idx==1&&cnt==1){
			idy++;
			cnt=0;
			continue;
		}
		if(cnt==0&&idx+1<=n){
			idx++;
		}else if(cnt==1&&idx-1>=1){
			idx--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<ans[i][j]<<" "; 
			if(ans[i][j]==xx){
				cout<<j<<" "<<i;
				return 0;
			}
		}
//		cout<<endl;
	}
	return 0;
}
