#include<iostream>
using namespace std;
long long n,k,a[1000005],p,ans,mark[1000005],mark1[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			p=a[l];
			for(int j=l+1;j<=r;j++){
				p^=a[j];
			}
			if(p==k&&mark[l]!=1&&mark1[r]!=1){
				ans++;
				mark[l]=1;
				mark1[r]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
