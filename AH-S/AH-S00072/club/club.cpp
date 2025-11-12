#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[0]>>a[1]>>a[2];
			sort(a,a+3);
			sum+=a[2];
		}
		cout<<sum<<'\n';
	}
	return 0;
}
