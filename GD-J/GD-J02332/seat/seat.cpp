#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace{
	int a[225],n,m,R;
	void Main(){
		cin.tie(0)->sync_with_stdio(0);
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n*m;i++) cin>>a[i];
		R=a[1];
		sort(a+1,a+n*m+1,greater<int>());
		int id=0;
		for(int i=1;i<=n*m;i++) if(a[i]==R){
			id=i;break;
		}
		int r=(id-1)/n+1;
		cout<<r<<" ";
		if(r&1) cout<<(id-1)%n+1;
		else cout<<n-((id-1)%n);
	}	
} 
main(){Main();}

