#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum,cnt;
bool f[5005];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			sum=a[i];
			if(sum==k){
				cnt++;
				f[i]=1;
			}else{
				for(int j=i+1;j<=n;j++){
					sum=sum^a[j];
					if(sum==k){
						cnt++;
						for(int i1=i;i1<=j;i1++){
							f[i1]=1;
						}
						break;
					}
				}
			}
		}
	} 
	cout<<cnt;
fclose(stdin);
fclose(stdout);
	return 0;
}
