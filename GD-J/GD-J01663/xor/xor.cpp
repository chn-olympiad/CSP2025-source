#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],cnt=-1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=a[i],ans=0,num=100001;
		for(int j=i+1;j<=n;){
			sum^=a[j];
			if(sum==k){
				ans++;
				num=min(num,i);
				j++;
				sum=a[j];
			}
			else{
				j++;
			}	
		}
		if(num<=1){
			cnt=max(cnt,ans)%99996;
			continue;
		}
		for(int j=1;j<num;j++){
			if(a[j]==k){
				ans++;
			}
		}
		cnt=max(cnt,ans)%99996;
	}
	cout<<cnt%99996;
	return 0;
}
