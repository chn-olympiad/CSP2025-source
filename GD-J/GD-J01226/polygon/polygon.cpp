#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],s[5010],maxx[5010],ans=0,flag=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		maxx[i]=max(maxx[i-1],a[i]);
		if(flag&&a[i]!=1)flag=0;
	}
	if(n==3){
		if(s[3]>(maxx[3]*2))cout<<"1";
		else cout<<"0";
		//return 0;
	}else if(flag){
		long long i=3,ans=0;
		while(i<=n){
			long long sum=1;
			for(int j=n;j>=n-i+1;j--)sum*=j;
			for(int j=i;j>=1;j--)sum/=j;
			ans+=sum;
			i++;
		}
		cout<<ans;
		//return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
