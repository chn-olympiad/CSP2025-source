#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
#define MOD 998244353
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<n-3;i++){
		for(int j=i+3;j<n;j++){
			unsigned long long int sum=0;
			int MAX=-1;
			for(int k=i;k<=j;k++){
				sum+=a[k];
				MAX=max(a[k],MAX);
			}
			MAX*=2;
			if(sum>MAX){
				ans++;
				ans%=MOD;
			}
		}
	}
	cout<<ans;
    return 0;
}
