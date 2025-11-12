#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn=110;
int n,m,sum,c,r;
int a[maxn],b[maxn];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			sum=i;
			break;
		}
	} 
	if(sum%n==0) c=sum/n;
	else c=sum/n+1;
	if(c%2==1){
		for(int i=1;i<=m;i++) if(a[i]-(c/2)*n*2==k) r=i;
	}
	else for(int i=n+1;i<=m+n;i++) if(a[i]-(c/2-1)*n*2==k) r=m-i+n+1;
	cout<<c<<" "<<r<<endl;
	return 0;
}