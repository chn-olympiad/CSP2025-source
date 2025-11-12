#include<bits/stdc++.h>
using namespace std;
long long n,m;
char a[100010];
int b[100010];
long long sum,ans=-2e9;
int f(int x){
	if(x==1){
		return 1;
	}
	return x*f(x-1);
}
int main(){
freopen ("employ.in","r",stdin);
freopen ("employ.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]=='0'){
		sum++;
		sum=sum%998244353;
	}else{
		ans=max(ans,sum);
		ans=ans%9962442353;
	}
}
for(int i=0;i<n;i++){
	cin>>b[i];
}
sum=0;
if(ans==0){
	 sum=(f(n-1)*n)%998244353;
	 cout<<sum;
	 return 0;
}
for(int i=0;i<n;i++){
	if(b[i]>=ans){
		sum++;
	}
}
cout<<((sum+1)/2)%998244353;
fclose(stdin);
fclose(stdout);	
	return 0;
} 
