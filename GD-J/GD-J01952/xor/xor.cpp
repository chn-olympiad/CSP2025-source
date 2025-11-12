#include<bits/stdc++.h>
using namespace std;
long long n,nk,a[500010],cnt;
bool b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>nk;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int jj=0;jj<n;jj++){
		for(int i=1;i<=n;i++){
			int j=i+jj;
			long long sum=a[i];
			for(int k=i+1;k<=j;k++){
				if(b[k]==1){
					sum=-1;
					break;
				} 
				else sum^=a[k];	 
			}
			if(sum==nk){
				for(int k=i;k<=j;k++) b[k]=1;
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
