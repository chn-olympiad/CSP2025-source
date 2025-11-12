#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d=-1,sum;
int a[15000];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=0;i<n;i++){
		cin >>a[i];
		d=max(d,a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]+a[j]>=d*2){
				sum++;
			}
		}
	}
	cout <<sum;
	return 0;
}
