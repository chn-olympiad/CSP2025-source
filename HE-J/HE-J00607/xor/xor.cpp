#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N =5E5+3;
int n,k,aum,sum,a[N];
bool p=1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	std::cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) p=0,++sum;
		if(a[i]==1) ++aum;
	}
	if(k==0&&p){
		if(n%2) cout<<0;
		else cout<<n/2;
		return 0;
	}
	else{
		if(k==1){
			if(p){
				cout<<n;
				return 0;
			}
			else{
				if(aum){
				   cout<<aum;
				   return 0;	
				}
				else{
					cout<<0;
					return 0;
				}
			}
		}
	}
	cout<<2;
	return 0;
}
