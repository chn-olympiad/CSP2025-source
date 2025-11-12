#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int n;
long long k;
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		long long num=0;
		for(int j=i;j<=n;j++){
			num^=a[j];
			if(num==k){
				cnt++;
				i=j+1;
				break;
			}
		}
	}
	return cnt<=x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		int mid=(r-l)/2+l;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
