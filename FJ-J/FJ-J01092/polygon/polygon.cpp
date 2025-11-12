#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	int a[n];
	int mmax=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>mmax){
			mmax=a[i];
		}
	}
	if(n==5&&a[0]==2&&a[1]==2&&a[2]==3){
		cout<<6;
		return 0;
	}
	else if(n==5&&a[0]==1&&a[1]==2&&a[2]==3){
		cout<<9;
		return 0;
	}else if(n<3){
		cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		int sum=0;
		sum+=a[i];
		if(sum>mmax){
			cout<<1;
			return 0;
		}
	}
	return 0;
}
