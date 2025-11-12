#include<bits/stdc++.h>
    using namespace std;
    long long a[500010],dp[500010];
    int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,ma=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
    ma=max(ma,a[i]);
    }
    if(n>1000&&ma<=1&&k<=1){
		long long s=0;
		if(k==0){
			a[0]=90;
			for(int i=1;i<=n;i++){
				if(a[i]==0)s++;
				else{
					if(a[i-1]==1){
						s++;
						a[i]=90;
					}
				}
			}
			cout<<s;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)s++;
			}
			cout<<s;
			return 0;
		}
	}
    for(int i=1;i<=n;i++){
    int p=-1,l=a[i],j=i-1;
    while(j>=0){
    if(l==k){
    p=j;
    break;
    }
    l=l^a[j];
    j--;
    }
    if(p==-1)dp[i]=dp[i-1];
    else dp[i]=max(dp[i-1],dp[p]+1);
    }
    cout<<dp[n];
    return 0;
    }
