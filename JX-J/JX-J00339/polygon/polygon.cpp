#include<bits/stdc++.h>
using namespace std;
int t[6000];
int n,k;
int kp(int m,int h,int p){
	if(m==0){
		k=p;
		return h;
	}
	for(int i=0;i<n;i++){
		p=max(t[i],p);
		return kp(m-1,h+t[i],p);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		int g=kp(i,0,0);
			if(g>2*k){
			ans++;
			ans%=998;
			ans%=244;
			ans%=355;
		}
	}
	printf("%d",ans);
	return 0;
}
