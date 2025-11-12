#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],k;
int b[N],sum;
int kk(int x,int y){
	int ans=0;
	for(int i=x+1;i<=y;i++){
		for(int j=1;j<=y-i+1;j++){
			if((b[i+j-1]^b[i-1])==m){
				if(j<=2){
					k=i+j-1;
					ans++;
				}
				else ans+=kk(i,i+j-1);
				i=k+1;
			}
		}
	} 
	if(ans==0&&x!=0){
		ans=1;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=2;i<=n;i++) b[i]=b[i]^b[i-1];
	k=n;
	cout<<kk(0,n)<<endl;
	return 0;
}
