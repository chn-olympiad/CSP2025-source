#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],sm[500005],cnt,cl=1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sm[i]=a[i]^sm[i-1];
		//cout<<sm[i]<<" ";
	}
	//cout<<endl;
	int l=1,r=1;
	while(r<=n){
		if((sm[r]^sm[l-1])==k){
			int x=(sm[r]^sm[l-1]);
		//	cout<<x<<" "<<l<<" "<<r<<endl;
			cl=r+1;
			cnt++;
			r++;
			l=r;
		}else{
			l--;
		}
		if(l>=r||l<cl)r++,l=r;
	}
	cout<<cnt;
	return 0;
}
