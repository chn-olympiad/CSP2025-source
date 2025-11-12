#include<bits/stdc++.h>
using namespace std;
int arr[5001];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		int j=0;
		while(j<=i) {
			int q=0;
			while(q<=i) {
				q++;
				if(arr[q]<arr[i]+arr[j] && arr[j]<arr[q]+arr[i] && arr[i]<arr[q]+arr[j]) sum++;
				sum/=998244353;
			}
		}
	}
	cout<<sum;
	return 0;
}
