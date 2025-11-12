#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);	
int n;
cin>>n;
int a[n+1];
int l=0,sum=0;
for(int i=1;i<=n;i++){
	cin>>a[i];
	}
for(int i=1;i<=n-2;i++){
	for(int j=i+1;j<=n-1;j++){
		for(int k=j+1;k<=n;k++){
			l=max(a[i],max(a[j],a[k]));
			if(2*l<a[i]+a[j]+a[k]){
				sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
