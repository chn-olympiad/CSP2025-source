#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long sum,ma;
bool v;
int main(){

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) v=1;
		}
	if(n<=3){
			for(int i=1;i<=n;i++){
				sum+=a[i];
				if(ma<a[i]){
					ma=a[i];
					}
			}
			if(sum>ma){
				cout<<1;
				}else{
					cout<<0;
					}
		}
		else if(v==0){
				for(int i=3;i<=n;i++){
					long long sa=1,sb=1;
					for(int j=n;j>=n-i+1;j--){
							sa*=j;
						}
					for(int j=i;j>=1;j--){
							sb*=j;
						}
						sum+=(sa/sb);
					}
					cout<<sum%998244353;
			}
		else cout<<n;
	return 0;
}
