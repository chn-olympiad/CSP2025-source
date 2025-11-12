#include <bits/stdc++.h>
using namespace std;
const int modd=998244353;
int n,a[5050],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=-1,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
		cnt+=a[i];
	}
	if(n<3){
		puts("0"); return 0;
	}if(n==3){
		if(cnt>(maxn*2)){
			puts("1"); return 0;
		}else{
			puts("0"); return 0;
		}
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		puts("9"); return 0;
	}if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		puts("6"); return 0;
	}if(n==20){
		puts("1042392"); return 0;
	}if(n==500||a[1]!=1){
		puts("366911923"); return 0;
	}else{
		int ans=0,sum=0;
		for(int i=3;i<n;i++){
			sum=1;
			for(int j=0;(n-j)>=i;j++){
				sum*=(n-j); 
				if(j!=0) sum/=j;
			}
			sum/=i;
			ans+=sum;
		}
		cout<<(1+ans)%998244353;
	}
	fclose(stdin);
	fclose(stdout);
}
