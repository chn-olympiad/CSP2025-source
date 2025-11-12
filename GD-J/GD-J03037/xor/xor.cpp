#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int a[N];
int sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int now_t=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1] xor a[i];
	}
	int ans=0;
	for(int j=now_t;j<=n;j++){
		for(int i=now_t;i<=j;i++){
			int temp=sum[j] xor sum[i-1];
			if(temp==k){
				ans++;
				now_t=j+1;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

