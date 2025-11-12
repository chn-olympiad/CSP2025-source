#include<bits/stdc++.h>
#define int long long
const int MOD=998244353; 
using namespace std;
int n,a[5010],ans;
//bool cmp(int x,int y){
//	return x>y;
//}
void kun(int z,int w){
	int ma=z*2,x=2,n2=w-1;
	for(int i=2;i<=n2;i++){
		x=x*2;
	}
	x-=1;
//	cout<<x<<endl;
	int b[x+10],k=1,sum=1,kk=1;
	for(int j=1;j<x;j++){
		if(sum<=n2){
			b[sum]=a[sum];
			sum++;
		}else{
			for(int i=k+1;i<=n2;i++){
				b[sum]=b[k]+b[i];
//				cout<<b[sum]<<" ";
				sum++;
			}
			if(k<=n2){
				k++;
			}else{
				k=kk+1;
				kk++;
			}
//			cout<<b[sum]<<" ";
		}
	}
//	cout<<sum;
	for(int i=1;i<x;i++){
		if(b[i]+z>ma){
			ans++;
		}
//		cout<<b[i]<<" ";
//        b[i]=0;
	}
//	cout<<endl;
//	cout<<ans<<" ";
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
//	sort(a+1,a+1+n,cmp);
//	cout<<a[n]<<" ";
	if(a[n]==1){//特判最大值为1 
		int n1=n-2,x=2;
//		cout<<n1<<" ";
		for(int i=2;i<=n1;i++){
			x*=2;
			x%=MOD;
		}
		cout<<x-1;
		return 0;
	}
	for(int i=n;i>=1;i--){
		kun(a[5],5);
	}
	cout<<ans;
	return  0;
}
