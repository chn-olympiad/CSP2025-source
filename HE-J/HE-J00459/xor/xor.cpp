#include<bits/stdc++.h>
using namespace std;
long long i,j,l,r,sum,n,k,num,a[10000100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	i=0;
	while(i<=n){
		i++;
		for(j=i;j<=n;j++){
			l=i,r=j;
			sum=a[l];
			for( k=l+1;k<=r;k++){
				sum=int(sum^a[k]);
			}
			if(sum==k){
				i=r+1;
				num++;
			} 
		}
	}
	cout<<num;
}

