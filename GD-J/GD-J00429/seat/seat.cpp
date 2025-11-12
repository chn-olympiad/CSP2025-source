#include<bits/stdc++.h>//iloveu ljn&Six_flower,pls giveme mwreluck for RP++!!! 
#define int long long//ur dependent,need a strong hear to helpu--but i'm also same asu
using namespace std;//so,my friend saythat our future impossible
int n,m;//i dont think hiswrong,but he's not right atall
int a,aa;
int ans;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>aa;
	for(int i=1;i<n*m;i++){
		cin>>a;
		ans+=(a>aa);
	}
	ans++;
//	cout<<ans<<'\n';
	if(ans%n==0){
		cout<<ans/n<<' '<<((ans/n)%2 ? n : 1);
	}else{
		cout<<ans/n+1<<' '<<((ans/n+1)%2 ? ans%n : n-ans%n+1);
	}
	return 0;
}
/*
2 2
99 100 97 98
*/
