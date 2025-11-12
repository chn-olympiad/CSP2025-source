#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],sum=0,i,j;
bool bl[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)
			sum++,bl[i]=1;
	}
	for(i=1;i<=n-1;i++){
		if(bl[i]==0){
			int o=a[i];
			for(j=i+1;j<=n;j++){
				if(bl[j]==0){
					o=o^a[j];
					if(o==k){
						sum++;
						for(int k=i;k<=j;k++)
							bl[k]=1;
						break;
					}
				}
				else
					break;
			}
			i=j;
		}
	}
	cout<<sum;
	return 0;
}
