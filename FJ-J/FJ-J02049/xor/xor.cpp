#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200500],s,b[200500],h=1,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
	cin>>a[i];	
	if(i==0)b[i]=a[i];
	else b[i]=a[i]^b[i-1];
	if(a[i]==k) {
		h=i+1;
		s++;
		continue;
	}
	
	for(int j=h;j<i;j++){
		if(j==1) {
			if(b[i]==k){
			s++;
			h=i+1;	
			break;
			} 
		}
		else {
			long long z=b[i]^b[j-1];
			if(z==k){
				s++;
				h=i+1;
			//	cout<<i<<" "<<j<<" "<<b[i]<<" "<<b[j]<<endl;
				break;
			}
		}
	}
	}
//	for(int i=1;i<=n;i++) cout<<b[i]<<" ";eggÎÒCÄãnima 
	cout<<s;
	return 0;
}
// 0 0  0
// 1 1  0
// 1 0  1
// 0 0 1 1

