#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,k,a[N],xor_sum[N],ans,f[N],l[N],t[N],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1||a[i]==0){
			cnt++;
			t[a[i]]++;
		}
		xor_sum[i]=xor_sum[i-1]^a[i];
	}
	if(cnt==n){
		cout<<t[k];
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int sum=xor_sum[j]^xor_sum[i-1];
				if(sum==k) l[j]=i;
			}
		}
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			if(l[i]>0) f[i]=max(f[i-1],f[l[i]-1]+1);
			f[i]=max(f[i],f[i-1]);
		}	
		cout<<f[n];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
