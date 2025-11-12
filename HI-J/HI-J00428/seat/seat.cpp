#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,m,r,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+1+n*m,greater<int>());
	int k;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			k=i;
			break;
		}
	}
	int col=1,flag=1;
	for(;k>n;col++){
		k-=n;
		flag=!flag;
	}
	if(flag==1) cout<<col<<' '<<k;
	else cout<<col<<' '<<n-k+1;
	return 0;
}
