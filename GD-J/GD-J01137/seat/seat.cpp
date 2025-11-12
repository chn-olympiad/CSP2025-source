#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;
const int N =25;
int n,m,cnt,ind,x,a[N*N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(rint i=1;i<=n*m;++i)
		cin>>a[i];
	x=a[1];
	stable_sort(a+1,a+1+n*m,cmp);
	for(rint i=1;i<=n*m;++i)
		if(a[i]==x) ind=i;
	for(rint i=1;i<=m;++i){
		if(i&1){
			for(rint j=1;j<=n;++j)
				if(++cnt==ind){
					cout<<i<<" "<<j;
					return 0;
				}
		}else{
			for(rint j=n;j>0;--j)
				if(++cnt==ind){
					cout<<i<<" "<<j;
					return 0;
				}
		}
	}
	return 0;
}

