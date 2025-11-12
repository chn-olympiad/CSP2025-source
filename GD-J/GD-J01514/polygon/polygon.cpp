#include<bits/stdc++.h>
using namespace std;
int n,a[6000],maxn,s[6000];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			maxn=0;
			for(int k=j;k<=j+i-1&&k<=n;k++){				
				maxn=max(maxn,a[j]);						
			}
			if(s[j+i-1]-s[j-1]>maxn*2){
				ans++;
				ans%=998;
				ans%=244;
				ans%=353;
			}
		}
	}		
	cout<<ans;
	return 0;
}

