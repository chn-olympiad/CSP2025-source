#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
unsigned long long n,k,a[maxn],ans,t;
bool vis[maxn],flag=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		t=a[i];
		flag=false;
		for(int j=i;j<=n;j++){
			for(int p=i+1;p<=j;p++){
				if(vis[p]) flag=true; 
				t^=a[p];
			}
			if(vis[j]) flag=true;
			if(t==k&&!flag){
				ans++;
				for(int p=i;p<=j;p++) vis[p]=true;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
