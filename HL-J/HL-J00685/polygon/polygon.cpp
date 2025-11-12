#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]+a[j]>n){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
