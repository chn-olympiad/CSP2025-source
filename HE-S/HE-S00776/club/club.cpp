#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	int max1=0;
	for(int i=0;i<=t;i++){                           
		cin>>n;
		int a[3][n];
		int count[3];
		for(int i=0;i<=n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			max1+=max(a[0][i],a[1][i],a[2][i]);
			cout<<max1;
		}
		return  0;
	}
}
