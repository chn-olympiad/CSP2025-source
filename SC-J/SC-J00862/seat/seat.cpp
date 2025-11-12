#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=110; 

ll a[N],sum,w;
ll n,m;
bool cmp(int q,int b){
	return q>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	ll q=n*m;
	for(int i=0;i<q;i++){
		cin>>a[i];
	} 
	sum=a[0];
	sort(a,a+q,cmp);
	for(ll i=0;i<q;i++){
		if(a[i]!=sum){
			continue;
		}
		else{
			w=i;
		}
	}
	ll k=w/m+1,j;
	if(k%2==0){
		j=m-w%m;
	}
	if(k%2==1){
		j=w%m+1;
	}
	cout<<k<<" "<<j;
	return 0;
} 