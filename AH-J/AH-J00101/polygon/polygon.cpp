#include<bits/stdc++.h>
using namespace std;
int n,a[5010],cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=3;j<=n;j++){
			int zd=0,lh=0;
			for(int k=i;k<i+j;k++){
				lh+=a[k];
				if(a[k]>zd){
					zd=a[k];
				}
			}
			if(lh>zd*2){
				cnt++;
			}
		}
	}
	cout<<cnt%998244353;
	return 0;
}
