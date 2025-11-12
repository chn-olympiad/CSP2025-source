#include<iostream>
#include<cstdio>
using namespace std;
long long n,cnt,ans,k,a[500005],b[1005][1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<n;i++){
		if(a[i]==k){
			ans++;
			continue;
		}
		long long x=a[i];
		for(int j=i+1;j<n;j++){
			if(a[j]==k)break;
			x^=a[j];
			if(x==k){
				i=j;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
