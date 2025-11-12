#include<bits/stdc++.h>
using namespace std;
int n,ans=0,a[5005];
long long x=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		x=0;
		for(int j=i;j<=n;j++){
			x+=a[j];
			if(a[j]*2<x){
				ans++;
			}
		}
	}
	cout <<ans;
	return 0;
}
