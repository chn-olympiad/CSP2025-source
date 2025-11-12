#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
struct{
	int i1,i2,i3;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int ans=0,Max=-1;
		for(int j=1;j<=n;j++){
			cin>>a[j].i1>>a[j].i2>>a[j].i3;
		}
		for(int j=1;j<=n;j++){
			Max=max(a[j].i1,a[j].i2);
			Max=max(Max,a[j].i3);
			ans+=Max;
		}
		cout<<ans;
	}
	return 0;
}
