#include<bits/stdc++.h>
using namespace std;
int arr[10010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int a,b;
		for(int i = 0;i < n;i++) cin>>arr[i]>>a>>b;
		sort(arr,arr+n);
        int cnt = 0;
        for(int i = n-1;i >= n/2;i--) cnt+=arr[i];
        cout<<cnt<<endl;
	}
	return 0;
}
