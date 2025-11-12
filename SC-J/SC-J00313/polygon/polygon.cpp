#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[50005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=n;i>=3;i--){
		for(int j=i-2;j>=1;j--){
			if(s[i]-s[j-1]>a[i]*2){
				sum++;
				for(int k=j+1;k<i;k++){
					if(a[k]<s[i]-s[j-1]-a[i]*2){
						sum++;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}