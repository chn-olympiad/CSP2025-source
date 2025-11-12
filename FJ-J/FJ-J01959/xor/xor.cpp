#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500002];
void solve1(){
	int cnt=0,g=1;
	for(int i=1;i<n;i++){
		int now=a[i];
		if(now==k)cnt++;//cout<<i<<" "<<i<<"\n";
		for(int j=i+1;j<=n;j++){
			now=now^a[j];
			if(now==k){
				cnt++;//cout<<i<<" "<<j<<"\n";
				g=j+1;
				break;
			}
		}
		i=g;
	}
	if(a[n]==k)cnt++;//cout<<n<<" "<<n<<"\n";
	cout<<cnt;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	solve1();
	return 0;
} 
