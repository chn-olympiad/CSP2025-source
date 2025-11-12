#include<bits/stdc++.h>
#define i64 long long
using namespace std;
const int maxn=105+5;
const int mod=1e9+7;
void solve();
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
int a[maxn];
void solve(){
	int n,m;
	cin>>n>>m;
	int N=n*m;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	int R=a[1],plc=0;
	sort(a+1,a+1+N,greater<int>());
	for(int i=1;i<=N;i++){
		if(a[i]==R){
			plc=i;
			break;
		}
	}
	int hang=0,lie=0;
	for(int i=1;i<=plc;i++){
		if(lie%2==0){
			hang--;
		}else{
			hang++;
		}
		if(hang>m || hang<1){
			lie++;
			if(lie%2==0){
				hang=m;
			}else{
				hang=1;
			}
		}
		
	}
	cout<<lie<<' '<<hang;
}

