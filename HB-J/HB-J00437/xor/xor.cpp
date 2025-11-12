#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum,v[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor,out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k){
			sum++;
			v[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		while(v[i]==0&&i<=n){
			int sum1=a[i];
			v[i]=1;
			i++;
			sum1=sum1^a[i];
			if(sum1==k){
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
