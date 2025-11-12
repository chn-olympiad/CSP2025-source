#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long qzh[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,sl=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(qzh[i]-qzh[j]>a[i]*2){
				sl++;
			}
		}
	}
	cout<<sl;
	return 0;
}
