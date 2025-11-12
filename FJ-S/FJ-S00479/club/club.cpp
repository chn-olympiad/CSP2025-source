#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
        int n;
		cin>>n;
		int a[100001]={0},b[100001]={0},c[100001]={0};
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1);
		long long sum=0;
		for(int i=n;i>n/2;i--){
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
} 
