#include<bits/stdc++.h>
using namespace std;

long long n,k,cnt=0;
long long a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			long long res=a[l];
			if(r-l>=2){
				for(int i=l+1;i<=r;i++){
					res^=a[i];
				}
			}
			if(res==k){
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
}
