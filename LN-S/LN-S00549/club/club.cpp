#include <bits/stdc++.h>
using namespace std;
struct member{
	int rate_1,rate_2,rate_3;
	int max_rate;
	
}a[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		//
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].rate_1>>a[i].rate_2>>a[i].rate_3;
			a[i].max_rate=max(max(a[i].rate_1,a[i].rate_2),a[i].rate_3);
		}
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i].max_rate;
		}
		cout<<sum<<endl;
	}
	fcloseall();
}
