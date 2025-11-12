#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long r=1,l=1;
	while(r<=n){
		int ank=a[l];
		for(int i=l+1;i<=r;i++){
			ank=ank^a[i];
		}
		if(ank==k){
		//	cout<<r<<" "<<l<<" ";
			l=r+1;
			r+=1;
			cnt++;
		//	cout<<cnt<<"\n";
		}
		else{r++;}
	}
	cout<<cnt;
	return 0;
}
