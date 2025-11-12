#include <bits/stdc++.h>
using namespace std;
int n,k,a[100005],sumz,sumo,sumoo,vis[100005],x,sum,c;
bool flagA=0,flagB=0,flagC=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if(k==1) flagA=1;
	if(k>1) flagB=1;
	if(k>255) flagC=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0) sumz++;
		if(a[i]==1) sumo++;
		if(a[i]==1&&a[i-1]==1&&!vis[i-1]){ 
			sumoo++;
			vis[i]++;
			vis[i-1]++;
		}
		if(a[i]!=1) flagA=1;
		if(a[i]!=1&&a[i]!=0) flagB=1;
		if(a[i]>255) flagC=1;
	}
	if(!flagA){
		cout << n/2;
	}else if(!flagB){
		if(k==1){
			cout << sumo;
		}else if(k==0){
			cout << (sumoo+sumz);
		}
	}else if(!flagC){
		for(int i=1;i<=n;i++){
			x=a[i];
			if(x==k){
				sum++;
				continue;
			}
			for(int j=i+1;j<=n;j++){
				c=a[j]^x;
				x=c;
				if(x==k){
					sum++;
					i=j;
					break;
				}
			}
		}
		cout << sum;
	}else{
		for(int i=1;i<=n;i++){
			x=a[i];
			if(x==k){
				sum++;
				continue;
			}
			for(int j=i+1;j<=n;j++){
				c=a[j]^x;
				x=c;
				if(x==k){
					sum++;
					i=j;
					break;
				}
			}
		}
		cout << sum;
	}
	return 0;
}
