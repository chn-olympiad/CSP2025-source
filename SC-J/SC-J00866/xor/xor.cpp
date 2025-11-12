#include<bits/stdc++.h>
using namespace std;
long long n,k,l=1,r=1,ans;
long long a[500005];
map<long long,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(r<=n&&l<=n){
		long long sum=0;
		for(int i=l;i<=r;i++){
			sum+=a[i];
			if(mp[a[i]]>0){
				sum=-1;
				break;
			}
		}
		if(sum==k){
			ans++;
			for(int i=l;i<=r;i++){
				mp[a[i]]=1;
			}
			r++;
			l=r;
		}else{
			if(r==n){
				l++;
				r=l-1;
			}
			r++;
		}
	}
	cout<<ans;
	return 0;
}