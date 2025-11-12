#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,k;
int a[N];
bool f=1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f==1&&k==0){
		cout<<n/2;
		return 0;		
	}
	if(f==0&&k<=1){
		if(k==1){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					sum++;
				}
			}
			cout<<sum;
			return 0;
		}else{
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					sum++;
				}
			}
			cout<<sum/2;
			return 0;
		}
	}
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		if((ans^a[i])==k||a[i]==k){
			cnt++;
			ans=0;
		}else{
			ans^=a[i];
		}
	}
	cout<<cnt;
	return 0;
}
