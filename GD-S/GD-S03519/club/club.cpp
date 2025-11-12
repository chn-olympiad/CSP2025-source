#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],x,y,ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>x>>y;
		} 
		sort(a+1,a+n+1);
		for(int i=n/2+1;i<=n;++i){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
