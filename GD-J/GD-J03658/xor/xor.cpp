#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N];
int cnt[N];
int ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	cin>>cnt[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		cnt[i]=cnt[i-1]^a[i];
	}
	int last=0;
	for(int i=0;i<n;i++){
		if(cnt[i]==k){
			ans++;
			last=i;
			break;
		}
	}
	int flag=0;
	for(int i=last+1,j=i;i<n,j<n;){
		while(j<n){
			int ssh=cnt[j]^cnt[i-1];
			if(ssh==k){
				flag=1;
				last=j;
				ans++;
				break;
			}
			j++;
		}
		if(flag==0){
			last=i;
		}
		i=last+1;
	}
	cout<<ans;
	return 0;
}
