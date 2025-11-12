#include<bits/stdc++.h>
using namespace std;
int a[101],sum,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++) cin>>a[i];
	c=a[1];
	sort(a+1,a+1+sum);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[sum--]==c){
				if(i%2==1) cout<<i<<" "<<j;
				else cout<<i<<" "<<n-j+1;
				return 0;}
	return 0;
} 