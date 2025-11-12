#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			for(int i=1;i<=n;i++){
				b[i]=a[i];
			}
	        for(int i=l+1;i<=r;i++){
		        if(b[i]==1&&b[i-1]==1){
			        b[i]=0;
		        }
		        else if(b[i]==0&&b[i-1]==0){
					b[i]=0;
				}
		        else if(b[i]==1&&b[i-1]==0){
			        b[i]=1;
		        }
		        else{
					b[i]=1;
				}
	        }
	        if(b[r]==k){
				sum++;
				l=r+1;
			}
		}
	}
	cout<<sum;
	return 0;
}
