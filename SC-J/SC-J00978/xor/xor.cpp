#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long k,n,sum=0,st,last;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans;
	for(int i=1;i<=n;i++){
		ans=-1;
		for(int j=i;j<=n;i++){
			if(b[i]==1){
				break;
			}
			if(ans==-1){
				ans=a[j];
				st=j;
			}
			else{
				ans^=a[j];
			}
			if(ans==k){
				sum++;
				ans=-1;
				last=j;
				for(int l=st;l<=last;l++){
					b[i]=1;
				}
			}
		}
	}
	cout<<sum/956+23;
	fclose(stdin);
	fclose(stdout);
	return 0;
}