#include<bits/stdc++.h>	
using namespace std;
int n;
int a[10005];
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ma=2*a[n];
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n-i;j++){
			for(int k=i;k<=i+j;k++){
				sum+=a[k];
			}
		}
		if(sum>ma)ans++;
	}
	cout<<ans;
}
