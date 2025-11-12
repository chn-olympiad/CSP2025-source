#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],cnt1,cnt0,c[500010][20],sum[500010][20],K[20],now=2e9,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) cnt1++;
		else if(a[i]==0) cnt0++;
	}
	if(cnt1+cnt0==n){
		if(k==1) printf("%d",cnt1);
		else{
			for(int i=2;i<=n;i++){
				if(a[i]==1&&a[i-1]==1) cnt0++,i++;
			}
			printf("%d",cnt0);
		}
	}
	else{
		int x=k,p=0;
		while(x){
			K[p]=x&1;
			x>>=1,p++;
		}
		memset(sum,0,sizeof sum);
		memset(c,0,sizeof c);
		for(int i=1;i<=n;i++){
			x=a[i],p=0;
			while(x){
				c[i][p]=x&1;
				x>>=1,p++;
			}
			for(int j=0;j<20;j++) sum[i][j]=sum[i-1][j]+c[i][j];
		}
		for(int i=1;i<=n;i++){
			if(i>now) cnt++,now=2e9;
			if(a[i]==k){now=i;continue;}
			for(int j=i+1;j<=n;j++){
				bool f=1;
				for(int q=0;q<20;q++){
					if(sum[j][q]-sum[i-1][q]!=K[q]) f=0;
				}
				if(f){now=min(now,j);break;}
			}
		}
		if(now==n) cnt++;
		printf("%d",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
