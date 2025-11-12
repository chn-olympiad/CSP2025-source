#include<bits/stdc++.h>
using namespace std;
int x[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,sum=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			int y,z;
			cin>>x[j]>>y>>z;
		}
		sort(x+1,x+n+1);
		for(int j=n/2+1;j<=n;j++){
			sum+=x[j];
		}
		cout<<sum;
	}
	return 0;
} 
