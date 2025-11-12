#include<bits/stdc++.h>
using namespace std;
long long sum,n,t;
long long a[100005];
long long q,w; 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>q>>w;
		}
		sort(a+1,a+n+1);
		for(int i=n;i>=n/2;i--){
			sum+=a[i];
		}
		cout<<sum<<'\n';
	}
 } 
