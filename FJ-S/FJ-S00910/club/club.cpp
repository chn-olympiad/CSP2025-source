#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long sum=0;
		int n,m=0;
		cin>>n;
		m=n/2;
			vector<int>a(n+1);
			vector<int>b(n+1);
			vector<int>c(n+1);
			for(int i=1;i<=n;i++){
				int a1,a2,a3;
				cin>>a1>>a2>>a3;
				if(a1>a2&&a1>a3){
					a.push_back(a1);
				}
				else if(a1<=a2&&a2>a3){
					b.push_back(a2);
				}
				else if(a3>=a2&&a1<=a3){
					c.push_back(a3);
				}}
				sort(a.begin(),a.end(),greater<int>());
				sort(b.begin(),b.end(),greater<int>());
				sort(c.begin(),c.end(),greater<int>());
				for(int i=1;i<=m/2;i++){
					sum+=a[i];
					sum+=b[i];
					sum+=c[i];
				}
				
			cout<<sum;		
	}
	return 0;
}
