#include<bits/stdc++.h>
using namespace std;
int a[10000]={};
int cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt=0;
	
	for(int i=0;i<n;i++){
		for(int j=i+2;j<n;j++){
			int maxi=0;
			for(int k=i+1;k<j;k++){
				maxi=max(a[i],max(a[j],a[k]));
				if((a[i]+a[j]+a[k])>maxi*2){
					cnt++;
				}
			}
			maxi=0;
			int sum=0;
			for(int k=i;k<=j;k++){
				maxi=max(maxi,a[k]);
				sum+=a[k];
			}
			if(sum>maxi*2){
				cnt++;
			}
		}
	}
	cout<<cnt%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
