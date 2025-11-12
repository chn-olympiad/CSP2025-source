#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=250;

ll n,m;

struct node{
	
	ll val,id;
}a[N];

inline bool cmp(node x,node y){
	
	return x.val>y.val;
}

int main(){
	
	//别忘了最后写 freopen~ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].val,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	
	ll cnt=0;
	for(int i=1;i<=m;i++){
		
		if(i&1){
			
			for(int j=1;j<=n;j++) if(a[++cnt].id==1) cout<<i<<' '<<j<<'\n';
		}
		else{
			
			for(int j=n;j>=1;j--) if(a[++cnt].id==1) cout<<i<<' '<<j<<'\n';
		}
	}
	
	return 0;
}
//9:02 meaw!
