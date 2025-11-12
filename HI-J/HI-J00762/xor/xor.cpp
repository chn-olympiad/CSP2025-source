#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+10;

int n,k;
int a[MAXN];
int ans=0,ji=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) {
			ans++;
			ji=0;
			continue;
		}
		else ji=ji^a[i];
		if(ji==k){
			ans++;
			ji=0;
		}
	}
	printf("%d",ans);
	return 0;
}
