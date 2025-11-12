#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20;
int n,m;
int s[N*N],sj=0,cnt=0;
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	sj=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=n;j>=1;j--){
			cnt++;
			int x=(i&1?n-j+1:j);
			if(s[cnt]==sj){
				cout<<i<<" "<<x;
				return 0;
			}
		}
	}
	return 0;
}
