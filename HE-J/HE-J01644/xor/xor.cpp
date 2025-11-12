#include <bits/stdc++.h>
using namespace std;

long long n,k;
const int N=5e5+10;
long long a[N];
bool chosen[N];

bool check(int l,int r){
	long long ans=a[l];
	for(int i=l+1;i<=r;i++){
		ans=(ans^a[i]);
	}
	if(k==ans){
		bool is_chosen=false;
		for(int i=l;i<=r;i++){
			if(chosen[i]){
				is_chosen=true;
				break;
			}
		}
		if(is_chosen){
			return false;
		}
		else{
			for(int i=l;i<=r;i++){
				chosen[i]=true;
			}
			return true;
		}
	}
	else return false;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int res=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			res+=check(i,j);
		}
	}
	cout<<res;
	return 0;
}
