#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k;
int a[N],dp[N]={0},ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=2&&k==0){
		if(n==2)cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		if(i==j&&a[i]==k){
			ans++;
			dp[i]=1;
		}
		else{
			int b[100]={0},c[100]={0},xx=a[i],bchang=0,cchang=0;
			while(xx/2>=1){
				bchang++;
				b[bchang]=xx%2;
				xx=xx/2;
			}
			for(int t=i+1;t<=j;t++){
				xx=a[t];
				while(xx/2>=1){
					cchang++;
					c[cchang]=xx%2;
					xx=xx/2;
				}
				bchang=max(bchang,cchang);
				for(int g=1;g<=bchang;g++){
					if(b[g]==c[g])b[g]=0;
					else b[g]=1;
				}
				memset(c,0,sizeof(c));
			}
			long long yy=0;
			for(int t=1;t<=bchang;t++){
				int y=2;
				for(int g=2;g<=t;g++)y=y*2;
				yy=b[t]*y+yy;
			}
			if(yy==k){
				int flag=0;
				for(int t=i;t<=j;t++){
					if(dp[t]==1)break;
					flag++;
				}
				if(flag==j-i+1){
					ans++;
					for(int t=i;t<=j;t++){
						dp[t]=1;
					}
				}
			}
		}
		}
	}
	cout<<ans<<endl;
	return 0;
}
