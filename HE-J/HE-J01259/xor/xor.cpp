#include<bits/stdc++.h>
using namespace std;
int n,k,f[2010][2010],ans=0,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&f[1][i]);
		if(f[1][i]==k){
			ans++;
			f[1][i]=-1;
		}
	}
	for(int i=2;i<=n;i++){
		cnt++;
		for(int j=i;j<=n;j++){
			f[i][j]=f[i-cnt][j]^f[i-1][j-1];
			if(f[i][j]==k){
				ans++;
				f[i][j]=-1;
				f[i-cnt][j]=-1;
			}
	    }
	}
	cout<<ans;
	return 0;
}
