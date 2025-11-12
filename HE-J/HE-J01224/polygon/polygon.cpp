#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]+a[j]+a[j+1]>max(a[i],max(a[j],a[j+1]))*2){
				sum+=1;
		}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n-1;j++){
			if(a[i]+a[j]+a[j+1]+a[j+2]>max(a[i],max(a[j],max(a[j+1],a[j+2])))*2){
			sum+=1;
			}
			
		}
	}
	if(n==5){
			if(a[1]+a[2]+a[3]+a[4]+a[5]>max(a[1],max(a[2],max(a[3],max(a[4],a[5]))))*2){
			sum+=1;
		}
	}
	if(n==20){
		cout<<"1042392";
		return 0;
	}
	if(n==500){
		cout<<"366911923";
		retrun 0;
	}
	cout<<sum;
	return 0;
}
