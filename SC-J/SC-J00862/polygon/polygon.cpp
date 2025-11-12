#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=110; 

ll a[N],sum,w;
ll n,k;
bool cmp(int q,int b){
	return q<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]*2<sum)
			cout<<1;
		else{
				cout<<0;
			}
			return 0;
	}
	sort(a,a+n,cmp);
	if(a[n]==1){
		sum=0;
		for(int i=0;i<=n;i++){
			sum+=n-i;
		}
		cout<<sum;
		return 0;
	}
} 
