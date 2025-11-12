#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],v[5005],sp,c,p;
long long num;
void dfs(int k,int io){
	if(sp>2*a[c]&&k>=3){
		num++;
	}
	for(int i=io+1;i<=n;i++){
		if(v[i]==0){
			if(a[i]>a[c]){
				p=c;
				c=i;
			}
			v[i]=1;
			sp+=a[i];
			dfs(++k,i);
			v[i]=0;
			sp-=a[i];
			c=p;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++){
		sp=a[i];
		c=i;
		v[i]=1;
		dfs(1,i);
		v[i]=0;
	}
	printf("%lld",num);
	return 0;
}
