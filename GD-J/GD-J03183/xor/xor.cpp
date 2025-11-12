#include<bits/stdc++.h>
using namespace std;
int n;
long long k,nums[500005];
struct tp{
	int lt,rt;
}ans[500005];
int ansN;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int tmp=nums[l];
			for(int i=l+1;i<=r;i++){
				tmp=tmp^nums[i];
			}
			if(tmp==k){
				ans[++ansN].lt=l;
				ans[ansN].rt=r;
			}
		}
	}
	cout<<ansN;
	return 0;
}
