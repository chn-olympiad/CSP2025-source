#include<bits/stdc++.h>
using namespace std;

int n,k,a[1000005],sum;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int t=a[i];
		for(int j=i;j<=n;j++){
			int x=a[i+1];
			if(i==j){
				x=a[i];
			}
			else{
				x=x^t;
				t=x;	
			}
			if(x==k){
				sum++;
				i=j;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
} 