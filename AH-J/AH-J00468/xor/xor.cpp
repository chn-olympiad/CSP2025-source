#include<bits/stdc++.h>
using namespace std;
int n,k,mx;
int a[500005];
int b[500005];
void init(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
		mx|=a[i];
	}
	return;
}
int ans=0;
void work(){
	int l=0;
	if(mx<k){
		cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>l;j--){
			if((b[i]^b[j-1])==k){
				ans++;
				l=i;
				break;
			}
			
		}
	}
	printf("%d",ans);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int t;
	//~ scanf("%d",&t);
	t=1;
	while(t--){
		init();
		work();
	}
	return 0;
}
