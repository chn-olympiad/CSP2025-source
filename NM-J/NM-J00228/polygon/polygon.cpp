#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009];
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	long long ans=0;
	if(n<=3){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i==3){
				if(a[1]+a[2]>2*a[3]){
					ans+=1;
				}
				if(a[1]+a[3]>2*a[2]){
					ans+=1;
				}
				if(a[2]+a[3]>a[1]*2){
					ans+=1;
				}
			}
			if(i==2){
				if(a[1]>a[2]*2){
					ans++;
				}
				if(a[2]>a[1]*2){
					ans++;
				}
			}
		}
		printf("%d",ans);
		return 0;
	}
	long long l=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		l=l*i;
	}
	printf("%d",(l/2)%998244353);
	fclose(stdin);
    fclose(stdout);
	return 0;
}
