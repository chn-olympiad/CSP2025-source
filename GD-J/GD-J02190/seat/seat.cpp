#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,tot,sum;
ll a[N];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%lld",&a[++tot]);
		}
	}
	sum=a[1];
	sort(a+1,a+tot+1,cmp);
	ll tx=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++tx]==sum){
					printf("%d %d",i,j);
					return 0;
				}
//				cout<<i<<" "<<j<<endl;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[++tx]==sum){
					printf("%d %d",i,j);
					return 0;
				}
//				cout<<i<<" "<<j<<endl;
			}
		}
	}
	return 0;
}
/*
4 5
12 19 18 17 16 15 14 20 12 11 10 9 8 7 6 5 4 3 2 1
*/
