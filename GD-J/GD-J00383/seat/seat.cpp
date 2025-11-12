#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005],x;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
			break;
		}
	}
	m=n*m;
	cout<<x/n+(int)(x%n!=0);
	cout<<" ";
	if((x/n+(int)(x%n!=0))%2==0) cout<<n-x%n+1;
	else cout<<(x-1)%n+1;
} 
