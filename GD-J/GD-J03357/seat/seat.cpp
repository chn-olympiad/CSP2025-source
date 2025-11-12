#include<bits/stdc++.h>
using namespace std;
int n,m,b,i,a[105];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n*m;i++){
		cin>>a[i];
		if(!i)b=a[i];
	}
	sort(a,a+n*m,greater<int>());
	for(i=0;i<n*m;i++)if(a[i]==b)return cout<<i/n+1<<' '<<((i/n)&1?m-i%n:i%n+1),0;
}
