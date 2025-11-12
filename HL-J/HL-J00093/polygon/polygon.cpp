#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n;
long long s=0,s1=0,vis[50005];
long long a[50005];
long long ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		vis[i]=0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<1;             
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}