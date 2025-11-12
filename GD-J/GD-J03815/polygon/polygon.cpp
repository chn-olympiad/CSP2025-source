#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
long long n,a[MAXN],ma,ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<3)printf("0");
	else if(n<=10){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int a1=k+1;a1<=n;a1++)
					for(int a2=a1+1;a2<=n;a2++)
					for(int a3=a2+1;a3<=n;a3++)
					for(int a4=a3+1;a4<=n;a4++)
					for(int a5=a4+1;a5<=n;a5++)
					for(int a6=a5+1;a6<=n;a6++)
					for(int a7=a6+1;a7<=n;a7++){
						ma=max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[a1]),a[a2]),a[a3]),a[a4]),a[a5]),a[a6]),a[a7]);
						if(a[i]+a[j]+a[k]+a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]>2*ma)ans++,ans%=998244353;
					}
				}
		if(n>=9){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int a1=k+1;a1<=n;a1++)
					for(int a2=a1+1;a2<=n;a2++)
					for(int a3=a2+1;a3<=n;a3++)
					for(int a4=a3+1;a4<=n;a4++)
					for(int a5=a4+1;a5<=n;a5++)
					for(int a6=a5+1;a6<=n;a6++){
						ma=max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[a1]),a[a2]),a[a3]),a[a4]),a[a5]),a[a6]);
						if(a[i]+a[j]+a[k]+a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]>2*ma)ans++,ans%=998244353;
					}
					
		}
		if(n>=8){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int a1=k+1;a1<=n;a1++)
					for(int a2=a1+1;a2<=n;a2++)
					for(int a3=a2+1;a3<=n;a3++)
					for(int a4=a3+1;a4<=n;a4++)
					for(int a5=a4+1;a5<=n;a5++){
						ma=max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[a1]),a[a2]),a[a3]),a[a4]),a[a5]);
						if(a[i]+a[j]+a[k]+a[a1]+a[a2]+a[a3]+a[a4]+a[a5]>2*ma)ans++,ans%=998244353;
					}
					}
		if(n>=7){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int a1=k+1;a1<=n;a1++)
					for(int a2=a1+1;a2<=n;a2++)
					for(int a3=a2+1;a3<=n;a3++)
					for(int a4=a3+1;a4<=n;a4++){
						ma=max(max(max(max(max(max(a[i],a[j]),a[k]),a[a1]),a[a2]),a[a3]),a[a4]);
						if(a[i]+a[j]+a[k]+a[a1]+a[a2]+a[a3]+a[a4]>2*ma)ans++,ans%=998244353;
					}
					}
		if(n>=6){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int a1=k+1;a1<=n;a1++)
					for(int a2=a1+1;a2<=n;a2++)
					for(int a3=a2+1;a3<=n;a3++){
						ma=max(max(max(max(max(a[i],a[j]),a[k]),a[a1]),a[a2]),a[a3]);
						if(a[i]+a[j]+a[k]+a[a1]+a[a2]+a[a3]>2*ma)ans++,ans%=998244353;
					}
					}
		if(n>=5){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int a1=k+1;a1<=n;a1++)
					for(int a2=a1+1;a2<=n;a2++){
						ma=max(max(max(max(a[i],a[j]),a[k]),a[a1]),a[a2]);
						if(a[i]+a[j]+a[k]+a[a1]+a[a2]>2*ma)ans++,ans%=998244353;
					}
					}
		if(n>=4){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int a1=k+1;a1<=n;a1++){
						ma=max(max(max(a[i],a[j]),a[k]),a[a1]);
						if(a[i]+a[j]+a[k]+a[a1]>2*ma)ans++,ans%=998244353;
					}
					
					}
		if(n>=3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ma=max(max(a[i],a[j]),a[k]);
					if(a[i]+a[j]+a[k]>2*ma){
						
						ans++,ans%=998244353;
					}
				}
			}
		}

	}
	printf("%lld",ans);
	return 0;
}
