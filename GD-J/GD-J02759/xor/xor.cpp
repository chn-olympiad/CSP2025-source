#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+101;
long long n,k,a[N],b[N],ans,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			b[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		int x=sum^a[i];
		if(b[i]==1){
			sum=0;
		}else if(x==k){
			ans++;
			sum=0;
		}else{
			sum=x;
		}
	}
	cout<<ans;
	return 0;
}
