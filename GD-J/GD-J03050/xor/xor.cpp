#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
short a[500005],p[30005][30005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int l=i;l<=j;l++){
				p[i][j]^=a[l];
			}
			if(p[i][j]==k){
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
