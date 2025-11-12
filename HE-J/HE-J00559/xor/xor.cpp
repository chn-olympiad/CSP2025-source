#include<bits/stdc++.h>
using namespace std;

int y=0,b=0,s=0;
long long n,k,a[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			y=1;
		}
		if(a[i]>=2){
			b=1;
		}
	}
	if(y==0&&k==0){
		cout<<n/2;
		return 0;
	}
	if(b==0){
		if(k==0){
			for(long long i=1;i<=n;i++){
				if(a[i]==0){
					s++;
				}
				if(a[i]==1&&a[i-1]==1){
					s++;
					a[i]=0;
				}
			}
			cout<<s;
			return 0;
		}
		else{
			for(long long i=1;i<=n;i++){
				if(a[i]==1){
					s++;
				}
			}
			cout<<s;
			return 0;
		}
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==k){
			s++;
		}
	}
	cout<<s;
	return 0;
}
