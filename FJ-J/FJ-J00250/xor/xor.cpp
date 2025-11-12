#include<bits/stdc++.h>
using namespace std;
int n,k,f=0,t=0;
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			f++;
		}
		else if(a[i]==0){
			t++;
		}
	}
	if(f==n){//È«ÊÇ1 
		cout<<n/2<<"\n";
	}
	else if(k==0){
		int ans=0,i=1;
		while(i<=n){
			 if(a[i]==0){
				ans++;
			}
			else if(a[i]==a[i+1]){
				ans++;
				i++;
			}
			i++;
		}
		cout<<ans<<"\n";
	}
	else if(f+t==n){
		cout<<f<<"\n";
	}
	return 0;
}
