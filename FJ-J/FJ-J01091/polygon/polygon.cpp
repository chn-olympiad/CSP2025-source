#include<bits/stdc++.h>
using namespace std;
int n,a[5001],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++){
				int maxn=max(a[i],a[j]);
				maxn=max(maxn,a[k]);
				if(a[i]+a[j]+a[k]>maxn*2) cnt++;
			}
	cout<<cnt;
	return 0;
}
