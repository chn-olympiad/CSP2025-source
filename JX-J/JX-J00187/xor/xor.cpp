#include<bits/stdc++.h>
using namespace std;
int n,k,ma=0,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int sum=a[i];
		for(int q=i-1;q>0;q--){
			if(sum==k){
				ma=max(i-q,ma);
				break;
			}
			sum=sum^a[q];
		}
		for(int j=n-1;j>i;j--){
			int cnt=a[j];
			for(int w=j-1;w>i;w--){
			if(cnt==k){
				ma=max(j-w,ma);
				break;
			}
			cnt=cnt^a[w];
			}
		}
	}
	cout<<ma;
	return 0;
}
