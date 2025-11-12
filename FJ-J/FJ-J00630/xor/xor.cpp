#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
unsigned long long a[N];
unsigned long long n,k,ans,pf;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)pf++;
	}
	unsigned long long l=1,r=2,res=a[1];
	if(res==k){
		ans++;
		res=0;
		l=r;
	}
	while(l<=r and r<=n){
		res^=a[r];
		if(res==k){
//			cout<<l<<" "<<r<<endl;
			ans++;
			r++;
			res=0;
			l=r;
		}
		else{
			r++;
		}
	}
	cout<<max(ans,pf);
	return 0;
}
