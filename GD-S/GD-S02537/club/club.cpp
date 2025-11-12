#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int b,c;
			cin>>a[i]>>b>>c;
		}
		int sum=0;
		sort(a+1,a+1+n);
		for(int i=n,sum=1;sum<=n/2;i--){
			sum+=a[i];
		}
		cout<<sum<<"\n";
	}
}
