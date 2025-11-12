#include<bits/stdc++.h>
using namespace std;
int n,t,sum=0;
int a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		sum=0;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		sort(a+1,a+n+1);
		for(int j=n;j>=n/2;j--){
			sum+=a[j];
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
