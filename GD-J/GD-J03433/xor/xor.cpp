#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[5000010],c[5000010],tim[5000010][2],l,late,ans;
int xh[5000010]; 
bool cmp(int x,int y){
	return tim[x][0]>tim[y][0];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		c[i]=(c[i-1]^a[i]);
		c[1]=a[1];
	}

	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((c[j]^c[i-1])==k){
				tim[++l][0]=i;
				tim[l][1]=j;
				xh[l]=l;
			}
		}
	}
	sort(xh+1,xh+l+1,cmp);
	late=n+1;

	for(int i=1;i<=l;i++){
		if(tim[xh[i]][1]<late){
			ans++;
			late=tim[xh[i]][0];
		}
	}
	cout<<ans;
	
	return 0;
}

