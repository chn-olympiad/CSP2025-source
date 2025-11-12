#include <bits/stdc++.h>
using namespace std;
int k,n,a[500010],sum,m,u;
int main(){
	freopen("xar.in","r",stdin);
	freopen("xar.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			sum++;
		}
		if(a[i]==1){
			m++;
		}
		if(a[i]>=0 and a[i]<=1){u++;}
	}
	if(k==0 and sum!=0){
		cout<<sum;return 0;
	}
	if(m==n){
		if(k==0){
			cout<<n/2;
		}
		else if(k==1){
			cout<<m;
		}
		return 0;
	}
	if(u==n and k==1){cout<<u-sum;}
	return 0;
}
