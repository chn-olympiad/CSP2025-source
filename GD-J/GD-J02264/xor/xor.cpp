#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[505005], n, k, cnt=0, ans=-1;
int __xor[505005];
int vis[505005];
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w",stdout);
	freopen();
	cin >> n >> k;
	cin >> a[1];
	__xor[1]=a[1];
	
	for(int i=2;i<=n;i++){
		cin >> a[i];
		__xor[i]=__xor[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		int j;
		bool flag=0;
		int s=0;
		for(j=i;j<=n;j++){
			s^=a[j];
			if(s==k&&!vis[j]){
				cnt++;
				vis[j]=i;
				flag=1;
				break;
			}
			vis[j]=i;
		}
		if(!flag){
			for(int k=j;k>=i;k--){
				vis[k]=0;
			}
		}
	}
	cout << cnt;
	return 0;
}
