#include<bits/stdc++.h>
using namespace std;
long long t,n,sum;
long long b[100005],c[100005],d[100005];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		sum=0;
		for(int j=1;j<=n;j++){
			cin>>b[j]>>c[j]>>d[j];
		}
		sort(b+1,b+n+1);
		for(int j=n;j>n/2;j--){
			sum+=b[j];
		}
		cout<<sum<<endl;
	}
	return 0;
}
