#include<iostream>
using namespace std;
const int N=5e5+5;
int n,k,ans;
int a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int l=1;l<=n;l++)
		for(int r=1;r<=n;r++){
			int s=sum[r]^sum[l-1];
			if(s==k){
				ans++;
				l=r+1,r++;
			}
		}
	cout<<ans;
	return 0;
}
