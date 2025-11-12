#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int x[2005][2005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int t=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=t;j++){
			x[i][j]=x[i-1][j-1]^a[i];
			if(x[i][j]==k){
				ans++;
				t=0;
				break;
			}
		}
		t++;
	}
	printf("%d",ans);
	return 0;
}
