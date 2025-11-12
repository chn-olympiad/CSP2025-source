#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a1,b;
	for(int i=1;i<=m;i++){
		cin>>a1>>b;
		cin>>a[i];
	}
	sort(a+1,a+1+m);
	long long sum=0;
	for(int i=1;i<=n-1;i++)
		sum=sum+a[i];
	cout<<sum;
	return 0;
}
