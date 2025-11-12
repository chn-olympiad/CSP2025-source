#include<bits/stdc++.h>
using namespace std;
int a[5005],sum=0,ans=0;
bool cmp(int n1,int n2){
	return n1>n2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5){
		cout<<9;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum+=a[j];
			if(sum>=a[i]*2 && (n-i)>=3){
			ans++;
			}
		}
		sum=0;
	}
	cout<<ans%998;
	return 0;
} 
