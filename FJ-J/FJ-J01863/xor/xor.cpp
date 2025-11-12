#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],sum[N],ans,cnt,l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans^=a[i];
		sum[i]=ans;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((sum[j]^sum[i-1])==k&&l<i){
				cnt++;
				l=j;
				break;
			}
	cout<<cnt;
	return 0;
}

