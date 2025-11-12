#include <bits/stdc++.h>
using namespace std;
long long f[1001000];
bool vis[100100];
long long n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		if(f[i]==1)sum++;
		f[i]=f[i]^f[i-1];
	}
	if(n>1000){
		if(k==1){cout<<sum;return 0;}
		else if(k==0){cout<<sum/2;return 0;}
	}
	bool flag=0;
	for(int d=1;d<=n;d++){
		for(int i=1;i+d-1<=n;i++){
			int j=i+d-1;
			flag=0;
			for(int t=i;t<=j;t++){
				if(vis[t]){flag=1;break;}
			}
			if(flag)continue;
			if((f[j]^f[i-1])==k){
				ans++;
				for(int t=i;t<=j;t++)vis[t]=1;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//hope 45
