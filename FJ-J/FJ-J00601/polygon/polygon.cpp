#include<bits/stdc++.h>
using namespace std;
int n,a[5000];
long long ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0";
	}
	sort(a+1,a+n+1);
    if(n==3)cout<<"1";
    if(n==4){
    	for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++)
    	for(int w=j+1;w<=n;w++){
    		if(a[i]+a[j]+a[w]>=a[n])ans++;
		}
	ans=ans+1;
	cout<<ans;
	}
	return 0;
}
