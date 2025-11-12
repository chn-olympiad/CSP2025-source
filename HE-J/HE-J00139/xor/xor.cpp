#include<bits/stdc++.h>
using namespace std;
long long n,k,a[111005],l=1,r=1,b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=l;i<=r;i++){
		while(r<=n){
			b=a[i]^a[i+1];
			if(l>=1&&l<=r){
				if(k==0&&n<=2){
			        a[i]=l;
		        }
		        else if(k<=1&&n<=10){
			        if(a[i]>=0&&a[i]<=l){
				        b=a[i]^a[i+1];
			        }
		        }
		        l++;
		        r++;
			}
		}
	}
	cout<<b<<'\n';
	return 0;
}
