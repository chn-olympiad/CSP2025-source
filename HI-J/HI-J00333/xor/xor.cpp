#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],b,sum;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=0;i<n;i++)cin>>a[i];
    b=n-1;
    while(b>=0){
    	long long x=a[b];
    	if(x==k){
			sum++;
			b--;
		}else if(b==0)break;
    	else{
    		for(long long i=b-1;i>=0;i--){
    			x=(x)xor(a[i]);
    			if(x==k || a[i]==k){
    				sum++;
					b=i-1;
					break;
				}else if(i<=0){
					b--;break;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
