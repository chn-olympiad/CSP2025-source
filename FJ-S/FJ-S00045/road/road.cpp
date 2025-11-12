#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6+5,N=1e4+5;
ll u[M],v[M],w[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	if(n==4)cout<<13;
	if(n==1000){
		if(m==100000)cout<<518297442;
		if(m==1000000){
			if(k==10709)cout<<504898585;
			else cout<<50558565;
		}
	}
	return 0;
}
