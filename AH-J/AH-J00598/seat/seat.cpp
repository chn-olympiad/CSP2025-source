#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int ans=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==t)ans=i;
	}
	cout<<ceil(ans*1.0/n)<<" ";
	int k=(ans-1)%(2*n)+1;
	if(k>=1&&k<=n)cout<<k;
	else cout<<2*n+1-k;
    return 0;
}
