#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500010],s[500010];
int f[500010];
int yh[5000010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=5e6;i++)yh[i]=-1;
	yh[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i],f[i-1]);
		if(yh[s[i]^k]!=-1){
			f[i]=max(f[i],f[yh[s[i]^k]]+1);
		}
		yh[s[i]]=i;
	}
	cout<<f[n]<<'\n';
	
	return 0;
}
/*
直接 dp 
然后用 f[i] 表示从 1 到 i 的答案 
但是需要快速求出距离这个数最近的异或值为 k 的数 
直接用前缀和 s[i] 
只需要找到最近的值为 s[i]^k 的就行了 
 
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3

*/