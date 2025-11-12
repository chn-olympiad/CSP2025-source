#include<cstdio>
using namespace std;
int ans=0,n,a[500005],k;
int main(){
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			int s=0;
			for(int i=l;i<=r;i++){
				s^=a[i];
			}
			if(s==k){
				l=r+1;
				ans++;
			}
		} 
	}
	printf("%d",ans);
	return 0;
} 
