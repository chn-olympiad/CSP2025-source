#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int a[110];
int n,m,f,t,v;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++){
		if(f==0){
			for(int j=1;j<=n;j++){
				v++;
				if(a[v]==t){cout<<i<<' '<<j;return 0;}
			}
			f=1;
		}else{
			for(int j=n;j>=1;j--){
				v++;
				if(a[v]==t){cout<<i<<' '<<j;return 0;}
			}
			f=0;
		}
	}
	return 0;
}
