#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],cnt,sum[N],pre;
int f[N][2];
struct QJ{
	int l,r;
}q[N];
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[i-1]^sum[j])==k){
				q[++cnt].l=i;
				q[cnt].r=j;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		f[i][1]=max(f[i-1][0]+(q[i].l>q[pre].r),f[i-1][1]+(q[i].l>q[i-1].r));
		if(f[i][1]>f[i][0]&&(f[i][1]>f[pre][1]||f[i][1]>f[i-1][1]))pre=i;  
	}
	cout<<max(f[cnt][0],f[cnt][1])<<"\n";
	return 0;
}         