#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    long long ans=0,x=-1;
    for(long long i=0;i<n;i++){
    	cin>>a[i];
	}for(long long i=0;i<n;i++){
    	if(a[i]==k){
    		ans++;
    		x=-1;
		}else if(x==-1){
			x=a[i];
		}else{
			x^=a[i];
			if(k==x){
				ans++;
				x=-1;
			}
		}
	}
	cout <<ans;
	return 0;
}
