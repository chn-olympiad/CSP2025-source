#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long l[5001];
long long a[5001],b[5001];
long long n,maxn=INT_MIN,sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(l,l+n);
	for(int i=1;i<n;i++)a[i]=a[i-1]+l[i];
	for(int i=2;i<n;i++){
		for(int j=0;j<=i;j++){
			if(a[i-1]+l[j]>l[i]){
				for(int k=i;k<=j;k++){
					if(a[i-1]-l[k]<=l[i]) break;
					else sum++;
				}
			}
			if(a[i-1]-a[j]+l[j]<=l[i]){	
				break;
			}
			
			if(a[i-1]-a[j]+l[j]>l[i]){
				b[i]=a[i-1]-a[j]+l[j];
				sum=sum%mod;
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
