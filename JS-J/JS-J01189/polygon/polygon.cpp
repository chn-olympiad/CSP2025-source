#include <bits/stdc++.h>
using namespace std;
int a[5005];
int sd[5005];
long long ans=0;
long long sum=1;
int yu=0;
int n;
void dp(int q,int b,int c,int d,int start){
	if(b==q){
		if(c>d){
			
			
			ans++;
			ans%=998244353;
		}
		return ;
	}
	
	for(int i=start;i<=n;i++){
		if(sd[i]!=1){
			c+=a[i];
			
			sd[i]=1;
			int p=d;
			d=max(d,a[i]*2);
			
			dp(q,b+1,c,d,i+1);
			sd[i]=0;
			c-=a[i];
			d=p;
		}
	}
	return ;
}	
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			yu=1;
		}
	}
	if(n==3){
		int po=a[1]+a[2]+a[3];
		int hu=max(a[1]*2,max(a[2]*2,a[3]*2));
		if(po>hu)
		cout<<1;
		else
		cout<<0;
	}
	else if(yu==1){
		for(int i=3;i<=n;i++){
			dp(i,0,0,0,1);
		}
		cout<<ans;
	}
	
	
	
	else{
	for(int i=3;i<=n;i++){
		sum=1;
		for(int j=0;j<=i-1;j++){
			sum*=(n-j);
			
		
			
			
			sum%=998244353;
		}
		for(int j=1;j<=i;j++){
			sum/=j;
			
		}
		ans+=sum;
		ans%=998244353;
	}
	cout<<ans;
}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
