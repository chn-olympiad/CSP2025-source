#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000+10],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int num=max(max(i,j),k);
				if(num*2<(a[i]+a[j]+a[k])) sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
