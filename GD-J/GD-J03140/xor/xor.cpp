#include<bits/stdc++.h>
using namespace std;
int n,a[2000001],x,k,minn,maxx;
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	if(minn==1&&maxx==1){
		printf("%d",n/2);
		return 0;
	}else if(minn==0&&maxx==1){
		if(k==1){
			for(int i=0;i<n;i++){
				if(a[i]){
					ans++;
				}
			}
			printf("%d",ans);
		}else{
			for(int i=0;i<n;i++){
				if(!a[i]){
					ans++;
				}
			}
			for(int i=0;i<n;i++){
				if(a[i]&&a[i+1]){
					a[i]=0;
					a[i+1]=0;
					ans++;
				}
			}
			printf("%d",ans);
		}
		return 0;
	}
	for(int i=0;i<n;i++){
		x=0;
		for(int j=0;j<=i+1;j++){
			x^=a[j];
		}
		if(x==k){
			ans++;
		}
		for(int j=1;j<n-i;j++){
			x^=a[j-1];
			x^=a[j+i+1];
			if(x==k){
				ans++;
			}
		}
	}
	return 0;
}
