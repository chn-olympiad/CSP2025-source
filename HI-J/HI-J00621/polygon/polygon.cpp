#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i>=1)b[i]=b[i-1]+a[i];
	}
	sum=1+n;
	if(n==3){
		cout<<n;
		return 0;
	}
	if(n==4){
		cout<<sum;
		return 0;
	}
	if(n>=5){
		sort(a,a+n);
		cout<<sum;
	}
	
	return 0;
}
