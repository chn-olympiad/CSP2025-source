#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1010];
inline bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			int x=(i+m-1)/m;
			if(x&1)cout<<x<<' '<<(i-1)%n+1;
			else cout<<x<<' '<<n-(i-1)%n;
			return 0;
		}
	}
	
	return 0;
}
//100 97
//99  98
