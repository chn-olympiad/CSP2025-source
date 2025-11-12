#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n][3];
		int maxi=0;
		int maxa=0;
		for(int j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			maxa=max(a[j][0],a[j][1],a[j][2]);
			maxi+=maxa;
		}
		cout<<maxi<<endl;
	}
	return 0;
}
