#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,k,a[200010],b[200010],c[200010],cnt0,cnt1,yn1[200010],yn2[200010],yna[200010];
int yl1,yl2,yla,yans;

int yh01(int x,int y){
	if(x+y==1)
		return 1;
	return 0;
}
int tyh(int x,int y){
	memset(yn1,sizeof(yn1),0);
	memset(yn2,sizeof(yn2),0);
	memset(yna,sizeof(yna),0);
	yl1=0;
	yl2=0;
	yla=0;
	yans=0;
	while(x){
		yl1++;
		yn1[yl1]=x%2;
		x/=2;
	}
	while(y){
		yl2++;
		yn2[yl2]=y%2;
		y/=2;
	}
	yla=max(yl1,yl2);
	for(int i=1;i<=yla;i++){
		yna[i]=yh01(yn1[i],yn2[i]);	
	}
	for(int i=1;i<=yla;i++){
		yans+=yna[i]*pow(2,i-1);
	}
	return yans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=yh01(b[i-1],a[i]);
		c[i]=tyh(c[i-1],a[i]);
		//printf("%d ",c[i]);
		if(a[i]==0)
			cnt0++;
		if(a[i]==1)
			cnt1++;
	}
	
	if(cnt1==n&&k==0){
		cout<<n/2;
		return 0;
	}
	if(cnt1+cnt0==n){
		int i=1,j=1;
		while(i<=n&&j<=n){
			while(yh01(b[i-1],b[j])!=k){
				j++;
			}
			ans++;
			i=j+1;
			j=i;
		}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//printf("%d %d %d\n",tyh(c[i-1],c[j]),i,j);
			if(tyh(c[i-1],c[j])==k){
				ans++;
				i=j+1;
				j=i;
			}
		}
	}
	cout<<ans;
	return 0;
}
