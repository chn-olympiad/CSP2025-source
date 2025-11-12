#include<bits/stdc++.h>
using namespace std;
int t,sum;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 1;i<=n;i++){
			int i1,i2,i3;
			cin>>i1>>i2>>i3;
			int j = max(max(i1,i2),max(i2,i3));
			sum+=j;
		}
		cout<<sum;
		sum = 0;
	}
	
	return 0;
}
