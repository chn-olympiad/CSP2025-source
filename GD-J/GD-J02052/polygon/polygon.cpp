#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
ll n,ar[5010],ans;
set<ll> st;
void df(int x,int lst,int sum){
	if(x==1){
		for(int i=lst;i<=n;i++){
			if(sum>ar[i]){
				ans++;
			}
		}
		return ;
	}
	for(int i=lst;i<=n-x+1;i++){
		df(x-1,i+1,sum+ar[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	sort(ar+1,ar+n+1);
	for(int i=3;i<=n;i++){
		df(i,1,0);
	}
	cout<<ans;
	
	
	return 0;
} 
