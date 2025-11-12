#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],op,po,o,p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			op=a[i];
			for(int kk=i+1;kk<=j;kk++){
				op=op^a[kk];
			}
			if(k==op){
				if(po==0){
					o=i;
					p=j;
					po++;
				}
				if(p<i){
					po++;
					o=i;
					p=j;
				}
				else if(p>=i){
					if(p-o+1>j-i+1){
						o=i;
						p=j;
					}
				}
			}
		}
	}
	cout<<po;
	return 0;
}
