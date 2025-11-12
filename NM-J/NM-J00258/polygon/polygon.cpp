#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
const int mod = 998244353;
int ma = INT_MIN;
int sum;
int n;
int a[N];
int cnt;
bool pd(int l,int r,int len){
	if(len<3)
		return false;
	for(int i=l;i<=r;i++){
		 sum += a[i];
		ma = max(ma,a[i]);
	}
	if(sum<=ma*2)
		return false;
	return true;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(pd(i,j,j-i)){
				cnt++;
			}
		}
	}
	cnt = cnt%mod;
	cout<<cnt;
	return 0;
}
