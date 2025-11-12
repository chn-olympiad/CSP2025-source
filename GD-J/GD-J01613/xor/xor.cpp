#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long zhi[500005];
long long mx;
void f(long long l,long long z){
	mx=max(mx,z);
	for(int i=l;i<=n;i++){
		if(zhi[i]) f(zhi[i]+1,z+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		int ans=0;
		for(int r=l;r<=n;r++){
			ans^=a[r];
			if(ans==k){
				zhi[l]=r;
				break;
			}
		}
	}
	f(1,0);
	cout<<mx<<endl;
	return 0;
}
