#include<bits/stdc++.h>
using namespace std;
int n,a[10000],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			int m=0,sum=0;
			for(int q=i;q<=j;q++){
				sum+=a[q];
				m=max(m,a[q]);
			}
			if(sum>m*2)cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
