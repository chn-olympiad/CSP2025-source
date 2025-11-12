#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
vector<int> v;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin >> n;
	bool all_is_one=true;
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		if(num!=1)all_is_one=0;
		v.push_back(num);
	}
	if(all_is_one){
		int sum[10000];
		sum[1]=1;
		for(int i=2;i<=n;i++)sum[i]=i*sum[i-1],sum[i]%=MOD;
		for(int i=3;i<=n;i++){
			ans+=sum[n]/sum[i];
			ans%=MOD;
		}cout << ans;
	}else{
		for(int z=0;z<(1<<n);z++){
			int sum=0,maxn=-1,cnt=0;
			for(int i=0;i<n;i++){
				if((z>>i)&1){
					sum+=v[i];
					maxn=max(maxn,v[i]);
					cnt++;
				}
			}
			if(cnt>=3&&sum>2*maxn){
//				cout << z <<endl;
				ans++;	
			}
		}
		cout << ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
