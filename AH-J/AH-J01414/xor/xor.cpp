#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],n,k,ans,l=1,r=1,x;
bool f=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	c[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1]^a[i];
	}
	if(k==0&&n<=2){
		if(n==2)cout<<1;
		else cout<<0;
		return 0;
	}
	int i=1,j=1;
	while(i<=n){
		j=i;
		f=0;
		while(j<=n){
			cout<<i<<" "<<j<<" "<<c[j]<<(~c[i-1])<<endl;
			if(i==1&&j==1&&c[1]==k){
				r=j;
				i=r+1;
				ans++;
				f=1;
				break;
			}
			if((c[j]^(abs(~c[i-1])))==k){
				r=j;
				i=r+1;
				ans++;
				f=1;
				break;
			}
			j++;
		}
		if(f==0)i++;
	}
	//for(int i=1;i<=n;i++){
		//for(int j=i;j<=n;j++){
			//if((c[j]^(!c[i-1]))==k){
			//	r=j;
			//	i=r+1;
				//ans++;
		//	}
		//}	
		//cout<<l<<" "<<r<<endl;
	//}
	cout<<ans;
	return 0;
} 
