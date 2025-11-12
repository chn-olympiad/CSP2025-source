#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000],nxb=1,zs,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=i;j>=nxb;j--){
			sum=sum^a[j];
			if(sum==k){
				zs++;
				sum=0;
				nxb=i+1;
				break;
			}
		}
	}
	cout<<zs;
	return 0;
}
