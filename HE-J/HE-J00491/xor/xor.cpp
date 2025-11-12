#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int p;
int ansl;
int q[1000010];
int a[1000010];
int b[1000010];
int f[1000010];
void bb(int x){
	if(x<=1){
		p++;
		q[p]=x;
		return ;
	}else{
		p++;
		q[p]=x%2;
		x/=2;
		bb(x);
	}
}
int xorr(int l,int r){
	int o=b[l];
	for(int i=l+1;i<=r;++i){
		if(o==b[i]) o=0;
		else o==1;
	}
	return o;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
    	cin>>a[i];
    	p=0;
    	ans=0;
    	memset(q,0,sizeof(q));
    	bb(a[i]);
    	for(int j=p;j>=1;--j){
    		ans=ans*10+q[j];
		}
		b[i]=ans;
	}
	if(n<=2&&k==0){
		printf("%d",n/2);
		return 0;
	}else if(n<=10&&k<=1){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j){
				if(xorr(j,i)==k&&f[i]!=1&&f[j]!=1){
					ansl++;
					f[j]=1;
					f[i]=1;
					break;
				}
			}
		}
	}
	printf("%d",ansl);
    return 0;
}
