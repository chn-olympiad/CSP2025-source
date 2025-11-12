#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],f[N];
bool pd1=1,pd=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)pd1=0;
		if(a[i]!=0&&a[i]!=1)pd=0;
	}
	if(pd1&&k==0){//A 10pts
		cout<<n/2;
		return 0;
	}
	if(pd&&k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=(a[i]==1);
		}
		cout<<ans;
		return 0;
	}
	if(pd&&k==0){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				cnt=0;
				if(cnt>0)ans+=cnt/2;
			}
			else if(a[i]==1)cnt++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
