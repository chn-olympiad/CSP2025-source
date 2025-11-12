#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+10;
long long n,k,a[maxn],b[maxn*100],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)    cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n-i+1;j++){
			long long ans=a[j],t=0;
			for(long long k=j+1;k<=j+i-1;k++){
				if(b[a[k]]==1)    t=1;
		        ans^=a[k];
			}
			if(ans==k&&t==0){
				sum++;
		    	for(long long k=j;k<=j+i-1;k++)    b[a[k]]=1;
			}
		}
	}
	cout<<sum;
	return 0;
}
