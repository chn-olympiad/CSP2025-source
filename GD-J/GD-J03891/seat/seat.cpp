#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7;
ll n,m,x,a[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
		x=a[1];
	}
	sort(a+1,a+1+n*m,greater<int>());
	ll i=1,j=0,k=1;
	while(true){
		if(i&1){
			j++;
			if(j>n){
				j--;
				i++;
			}
		}
		else{
			j--;
			if(j<1){
				j++;
				i++;
			}
		}
		if(a[k++]==x){
			break;
		}
	}
	cout<<i<<" "<<j<<endl;
	return 0;
}
