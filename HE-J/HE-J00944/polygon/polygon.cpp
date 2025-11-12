#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	int ans=0;
	int maxn=0;
	for(int i=3;i<=n;i++){
		sum=0;
		maxn=0;
		for(int j=1;j<=n;j++){
			for(int k=j;k<=j+1;k++){
				sum+=a[k];
				maxn=max(maxn,a[k]);
			}
		}
		maxn*=2;
		if(sum>=maxn){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
