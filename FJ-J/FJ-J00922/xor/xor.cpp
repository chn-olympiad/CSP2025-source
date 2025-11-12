#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],b[100005],cnt,i,j,bo,ans;
int main(){
//	freopen("D:\\number4.in","r",stdin);

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	cin>>a[1];
	b[1]=a[1];
	for(i=2;i<=n;i++){
		cin>>a[i];
		b[i]=(a[i]^b[i-1]);
	}
//	for(i=1;i<=n;i++){
//		cout<<(b[i]^b[i-1]);
//	}cout<<endl;
	for(i=1;i<=n;i++){
		for(j=i-1;j>=cnt;j--){
			if((b[i]^b[j])==k){
		//		cout<<b[i]<<' '<<b[j-1]<<'*'<<(b[i]^b[j-1])<<' '<<k<<endl;
				cnt=i;
		//		cout<<i<<' '<<j<<endl;
				ans++;
				break;
			} 
		}
	}
	cout<<ans<<endl;
	return 0;
}
