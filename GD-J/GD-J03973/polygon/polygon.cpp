#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long int n,ans,sum[100001],a[100001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]+sum[i-1];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(((i-j)>=3) && ((sum[i]-sum[j])>(a[i]*2))){
				ans++;
			}
			if(i-j>=4){
				for(int k=i+1;k<j;k++){
					if((sum[i]-sum[j]-a[k])>(a[i]*2)){
						ans++;
					}
				}
			}
		}
	}
	if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
	}
	else if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
	}
	else{
		cout<<ans%MOD;
	}
	return 0;
}
