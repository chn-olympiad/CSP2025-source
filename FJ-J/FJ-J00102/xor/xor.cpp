#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,h=0;
	cin>>n>>k;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=1;
	while(l<n+1){
		if(l==r){
			if(a[l]==k){
				h++;
				r++;
				l++;
				continue;
			}else if(a[l]>k){
				r++;
				l++;
				continue;
			}
			
		}else{
			int s=0;
			for(int i=l;i<=r;i++){
				s=(s^a[i]);
			}
			if(s==k){
				h++;
				l=r+1;
				r++;
				continue;
			}else if(s>k){
				l++;
				continue;
			}
		}
		if(r>=n){
			l++;
			r=n;
		}else{
			r++;
		}
	}
	cout<<h;
	return 0;
}