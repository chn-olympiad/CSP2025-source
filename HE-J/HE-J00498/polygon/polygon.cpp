#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<n;i++){
		int ji=1;
		for(int j=1;i<=i;j++){
			ji=ji*(n-j+1);
		}
		cnt+=ji;
	}
	return 0;
} 
