#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],xs[500010],cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xs[i]=xs[i-1] xor a[i];
	}
	int last=1;
	for(int i=1;i<=n;i++){
		for(int j=last;j<=i;j++){
			if(j==1){
				if(xs[i]==k){
					cnt++;
					last=i+1;
					break;
				}
			}
			else if((xs[i] xor xs[j-1])==k){
				cnt++;
				last=i+1;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
