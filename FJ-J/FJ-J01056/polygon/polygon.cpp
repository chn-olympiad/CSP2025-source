#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if((i==3&&a[i-2]+a[i-1]>=a[i])&&a[i-2]+a[i-1]+a[i]/2>=1){
			cnt++;
		}
		else if((i>3&&i<n)&&a[n-i+1]+a[i-1]+a[i]+a[i+1]/2>=1){
			cnt++;
		}
		else{
			cnt++;
		}
	}
	cout<<cnt;
}
