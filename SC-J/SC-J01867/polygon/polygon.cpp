#include<bits/stdc++.h>
using namespace std;

int n;
int a[5010];
long long qzh[5010];
long long ans=0;

int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j;
	cin>>n;
	
	for(i=1;i<=n;i++){
		int c;
		scanf("%d",&c);
		a[i]=c;
	}
	
	sort(a+1,a+n+1);
	
	for(i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
		for(j=i-3;j>=1;j--){
			long long sum=qzh[i]-qzh[j-1];
			if(sum>2*a[i]){
				ans++;
				long long cha=sum-2*a[i]-1;
				long long s=0;
				long long num=0;
				for(int l=j+1;l<=i-2&&s<=cha;l++){
					s+=a[l];
					num++;
				}
				if(num==0){
					ans++;
					ans%=998244353;
					continue;
				}
				//cout<<j<<' '<<i<<' '<<num<<' '<<cha<<'\n';
				ans+=num*(num+1)/2;
				ans%=998244353;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}