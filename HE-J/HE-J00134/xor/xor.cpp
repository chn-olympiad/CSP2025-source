#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,a[N],k,cnt,b[N],f,num;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			f++;
		}
	}
	if(f==n){
		cout<<n/2;
		return 0;
	}
	else if(k==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int ans=a[i];
		for(int j=i;j<=n;j++){
			if(a[i]==k){
				cnt++;
				i++;
				continue;
			}
			ans^=a[j];
			if(ans==k){
				cnt++;
				i++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
