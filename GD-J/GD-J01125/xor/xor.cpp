#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) b[i]=a[i];
		else if(a[i]==0) b[i]=b[i-1];
		else b[i]=a[i]^b[i-1];
	}
	/*cout<<"\n";
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	cout<<"\n\n";*/
	int i=1,j=1;
	while(i<=n){
		int f=0,d=b[j]^b[i-1];
		if(i==j&&a[i]==k){
			//cout<<1<<" "<<i<<" "<<j<<"\n";
			ans++;
			i++;
			j=i;
			f=1;
		}
		else if(i==1&&b[j]==k){
			//cout<<2<<" "<<i<<" "<<j<<"\n";
			ans++;
			f=1;
			if(i==j){
				i++;
				j=i;
			}
			else{
				i=j+1;
				j=i;
			}
		}
		else if(d==k&&b[i-1]!=0){
			//cout<<3<<" "<<d<<" "<<i<<" "<<j<<"\n";
			ans++;
			f=1;
			if(i==j){
				i++;
				j=i;
			}
			else{
				i=j+1;
				j=i;
			}
		}
		if(!f){
			if(j==n){
				i++;
				j=i;
			}
			else j++;
		}
	}
	cout<<ans;
	return 0;
}
