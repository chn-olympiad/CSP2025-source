#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500010];
int val[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int maxn=-1,minn=256;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>maxn)maxn=a[i];
		if(a[i]<minn)minn=a[i];
	}
	if(maxn==minn&&minn==1){
		if(k==0){
			if(n%2==0)cout<<n/2;
			else cout<<n/2-1;
		}
	}else if(maxn==1&&minn==0){
		if(k==0){
			for(int i=1;i<=n;++i){
				if(a[i]==0)cnt++;
				if(a[i]==1&&a[i-1]==1&&!val[i]){
					cnt++;val[i]++;
				}
			}
		}else{
			for(int i=1;i<=n;++i){
				if(a[i]==1)cnt++;
				if(a[i]==0&&a[i-1]==0&&!val[i]){
					cnt++;val[i]++;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
} 