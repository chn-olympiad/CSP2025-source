#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k,a[N],i,j,s,c,sum=0,cnt=0;
int d[N]
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=0;i<n;i++)cin>>a[i];
	for(s=1;s<=n;s++){
		for(c=0;c<n-s+1;c++){
			for(i=c;i<s+c;i++){
				sum+=a[i]^a[i+1];
			}
			if(sum==k)cnt++;
		}
	}
	cout<<c;
	return 0;
}