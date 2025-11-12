#include<bits/stdc++.h>
using namespace std;
int a[5050];
int big(int x,int n,int j){
	int sum=0;
	for(int i=j;i<=n;i++){
		if(x>a[i])sum++;
		else break;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,f=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f+=a[i];
	}
	sort(a,a+n);
	for(int p=1;p<=n-2;p++){
		for(int i=p+1;i<=n-1;i++){
			int x=a[p]+a[i];
			for(int j=i+1;j<=n;j++){
				ans+=big(x,n,j);
				x+=a[j];
				//cout<<x<<" ";
			}
		}
	}
	if(f-a[n]>a[n])ans++;
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
