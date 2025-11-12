#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll l[25];
set<ll> ans;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	if(l[n]==1) cout<<(n-1)*(n-2)/2<<endl;
	else{
		
		for(ll k=8;k<(1<<(n+1));k++){
			ll maxn=-114514;
			ll tot=0,cot=0;
			for(int i=1;i<=n;i++){
					if((k&(1<<i))){
					//cout<<i<<" ";
					tot+=l[i];
					cot++;
					maxn=max(maxn,l[i]);
				}
			}
	//		cout<<endl<<endl;;
			if(tot>2*maxn && cot>=3 && (k&1)==0){
	//			cout<<"Y"<<endl;
				ans.insert(k);
			}
		}
		cout<<ans.size()<<endl;
	}
	return 0;
}
