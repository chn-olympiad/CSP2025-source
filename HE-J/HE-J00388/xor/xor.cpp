#include <bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
#define int long long
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			continue;
		}
		cnt=a[i];
		for(int j=1;j<=n;j++){
			for(int q=j;q<=n;q++){
				cnt=cnt&a[j];
			}
			if(cnt==k){
				ans++;
			}
			
		}
	}
	cout<<ans<<endl;
	return 0;
	                                                                             
}

