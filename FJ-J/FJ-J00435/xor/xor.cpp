#include <iostream>
using namespace std;
int n,k,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n+5],l[n+5]={0},r[n+5]={0};
	r[0]=n+1;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==k){
    		sum++;
    		l[sum]=i;
    		r[sum]=i;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=sum+1;j++){
			for(int k=l[j+1];k<r[j];k++){
				a[k]=a[k+1]^a[k];
				if(a[k]==k){
					sum++;
					l[sum]=k;
					r[sum]=k+i-1;
					k+=i;
				}
			}
		}
	}
	cout<<sum;
}
