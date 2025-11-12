#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],x=1,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	for(int i=1;i<n*m;i++)
		if(a[i]>a[0])
			x++;
	ans1=(x-1)/n+1;
	if(ans1&1) ans2=(x-1)%n+1;
	else ans2=n-(x-1)%n;
	cout<<ans1<<" "<<ans2;
	return 0;
}
