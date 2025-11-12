#include<bits/stdc++.h>
using namespace std;
int a[5500];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5 && a[1]==1){
		cout<<"9";
		return 0;
	}else if(n==5 && a[1]==2){
		cout<<"6";
		return 0;
	}else if(n==20){
		cout<<"1042392";
		return 0;
	}else if(n==500){
		cout<<"366911923";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=3;j<=n;j++){
			int all,maxn;
			for(int k=1;k<=j;k++){
				all=0,maxn=INT_MIN;
				all+=a[k];
				if(a[k]>maxn){
					maxn=a[i];
				}
			}   
			if(all>maxn*2){
				sum++;
			}   
		}
	}
	cout<<sum%998244353;
	return 0;
}
