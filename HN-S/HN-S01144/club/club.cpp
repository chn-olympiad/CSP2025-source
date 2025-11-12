#include<bits/stdc++.h>
#define long long int
using namespace std;
int n,t,a[100000][3],sum,summ;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=0;i<n;i++){
			summ=max(a[i][1],a[i][2]);
			sum=sum+max(a[i][3],summ);
		}
		cout<<sum;
		sum=0;summ=0;
	}
	return 0;
} 
