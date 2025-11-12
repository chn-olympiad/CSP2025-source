#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+2;
int n,k;
int a[N],f[N][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[1][0] = f[1][1] = 0;
	if(a[1]==k)f[1][1] = 1;
	for(int i=2;i<=n;i++){
		int x = 0,sum = -1000,a1;
		f[i][0] = max(f[i-1][0],f[i-1][1]);
		for(int j=i;j>=1;j--){
			x = x^a[j];
			sum = max(f[j-1][0],f[j-1][1]);
			if(j==i)a1 = sum;
			if(a1-sum>1)break;
			if(x==k)sum++;
			f[i][1] = max(f[i][1],sum);
		}
	}
	cout<<max(f[n][1],f[n][0]);
	return 0;
}



