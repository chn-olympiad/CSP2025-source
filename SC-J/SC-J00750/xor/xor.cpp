#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	int ans=0;
	int l=1,r=1,cnt=1;
	while(r<=n){
		int flag=0;
		for(l=cnt;l<=r;++l){
			long long q=a[l];
			for(int i=l+1;i<=r;++i){
				q=q^a[i];
			}
			if(q==k){
		 		cnt=r+1,++r;
				++ans;
				flag=1;
				break;
			}
		}
		if(flag==1){
			continue;
		}
		else if(flag==0){
			++r;
		}
	}
	printf("%d",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
