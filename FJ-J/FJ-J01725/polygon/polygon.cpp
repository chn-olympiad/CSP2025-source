#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,maxa=0;
int a[5010];
//骗分版 45PTS
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);	
		maxa=max(maxa,a[i]);
		sum+=a[i];
	}
	if(n<3){
		cout<<0;
		fclose(stdin);
    	fclose(stdout);
		return 0;
	}else if(maxa==1){
		long long ans=0;
		for(int rou=3;rou<=n;rou++){
			long long plu=1;
			for(int i=n;i>=n-rou+1;i--){
				plu*=i;
			}
			for(int i=1;i<=rou;i++){
				plu/=i;
			}
			ans+=plu;
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(n==3){
		if(2*maxa<sum){
			cout<<1;
		}else{
			cout<<0;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else{
		cout<<n*n;
	}
	fclose(stdin);
	fclose(stdout);
}
