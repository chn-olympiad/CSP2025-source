#include<bits/stdc++.h>
using namespace std;
int b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num=0;
	cin>>n>>k;
	int a[n+5];
	a[0]=0;cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			int op=0;
			if((a[i-1]^a[j])==k){
				for(int m=i;m<=j;m++){
					if(b[m]!=0){
						op++;
						m=j+1;
					}
				}
				if(op==0){
					num++;
					b[i]=1;b[j]=1;
					j=n+1;
				}
			}
		}
	}
	cout<<num;
	return 0;
}
