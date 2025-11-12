#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005];
int s[1000005];//前缀异或和
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];//使用前缀异或和,O(1)求出区间权值
	}
	int r=0,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=r;j--){//按照区间最大数量模板求解,实际上时间复杂度不到O(n^2)，接近O(n)
			int px=s[i]^s[j-1];
			//~ cout<<"l="<<i<<" r="<<j<<" prefix_xor="<<px<<endl;
			if(px==k){//可以加入
				ans++;
				r=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0; 
}
