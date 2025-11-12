#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m=0;
	cin>>n>>m;
	int arr[n],arr1[n];
	for(int i=0;i<n;i++){
        cin>>arr[i];
	}
	for(int i=0;i<n;i++){
        cin>>arr1[i];
	}
	int result=1;
	for(int i=1;i<=n;i++){
        result=(i%998244353)*(result%988244353);
	}
	cout<<result%998244353;
	return 0;
}
