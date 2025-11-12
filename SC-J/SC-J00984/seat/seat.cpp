#include<bits/stdc++.h>
using namespace std;
int n,m,a[1006];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	int cnt=0;
	for(int i=2;i<=n*m;i++){
		if(a[i]>ans){
			cnt++;
		}
	}
	int l=(cnt+n)/n;
	int a=cnt%n;
	if(l%2==1){
		cout<<l<<" "<<a+1;
	}
	else cout<<l<<" "<<(n-a);
}