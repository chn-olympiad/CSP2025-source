#include<bits/stdc++.h>
using namespace std;
int n,a[11451],b[5145],lo,su,ans;
bool pdd(){
	int ma=0;
	for(int i=0;i<lo;i++){
		ma=max(ma,b[i]);
	}
	return(su>2*ma);
}
int pl(int x,int y){
	if(y==0){
		return pdd();
	}
	int sum=0;
	for(int q=x;q<n-y+1;q++){
		b[lo]=a[q];
		lo++;
		su+=a[q];
		sum+=pl(q+1,y-1);
		su-=a[q];
		lo--;
		b[lo]=0;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;i++){
		ans+=pl(0,i);
		ans%=998244353;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
