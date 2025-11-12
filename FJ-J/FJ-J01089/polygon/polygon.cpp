#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005];
long long sum=0;
long long maxx=INT_MIN;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(sum<=maxx*2){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
