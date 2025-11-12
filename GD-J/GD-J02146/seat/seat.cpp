#include<bits/stdc++.h>
using namespace std;
int n,m,qwq;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	qwq=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==qwq){
			int t=2*n;
			if(!(i%t)) cout<<i/t*2<<' '<<1;
			else if((i%t)<=n) cout<<(i/t+1)*2-1<<' '<<i%t;
			else cout<<(i/t+1)*2<<' '<<n-(i%t-n)+1;
			return 0;
		}
	}
	return 0;
}
