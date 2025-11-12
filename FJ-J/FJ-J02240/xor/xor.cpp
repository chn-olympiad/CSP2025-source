#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool all_eq1=1,all_le2=1;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1)all_eq1=0;
		if(a[i]>=2)all_le2=0;
	}
	if(all_eq1){
		cout<<n/2;
		return 0;
	}else if(all_le2){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[i]==k)++cnt;
			else if((a[i]^a[i+1])==k)++i,++cnt;
		}
		cout<<cnt;
		return 0;
	}else{
		int maxn=-1;
		int ans=1e9;
		for(int i=1;i<=n;++i)maxn=max(maxn,a[i]);
		while(maxn){
			int cnt=0;
			for(int i=1;i<=n;++i){
				if(a[i]&1==k&1)++cnt;
				else if( ( (a[i]&1) ^ (a[i+1]&1) )==k&1)++i,++cnt;
			}
			for(int i=1;i<=n;++i)a[i]>>=1;
			k>>=1,maxn>>=1;
			if(cnt!=0)ans=min(ans,cnt);
//			cout<<"cnt"<<maxn<<" "<<cnt<<"\n";
		}
		cout<<ans;
	}

	return 0;
}

