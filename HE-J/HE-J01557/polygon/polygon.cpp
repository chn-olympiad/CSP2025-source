#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0;
	cin>>n;
	int a[n];
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i!=1){
			if(a[n-i-2]+a[n-i-1]+a[n-i]>max(a[n-i-2],max(a[n-i-1],a[n-i]))){
				num++;
			}
			if(a[n-i-1]+a[n-i]+a[n-i+1]+a[n-i+2]>max(a[n-i-1],max(a[n-i-0],max(a[n-i+1],a[n-i+2])))){
				num++;
			}
			if(a[n-i-4]+a[n-i-3]+a[n-i-2]+a[n-i-1]>max(a[n-i-4],max(a[n-i-3],max(a[n-i-2],a[n-i-1])))){
				num++;
			}
		}
	}
	num++;
	cout<<num%998244353;
	
	return 0;
}
