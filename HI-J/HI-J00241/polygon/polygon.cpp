#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int n,a[5005],b[5005];
long long ans=0; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
	}
	sort(a+1,a+n+1);
	for(int j=3;j<=n;j++){
		while(1){
		int c=0;
		for(int i=1;i<=j;i++) c+=a[b[i]];
		if(c>2*a[b[j]]){
			ans++;
			//for(int i=1;i<=j;i++) cout<<b[i]<<" ";
			//cout<<endl;
		}
		if(b[1]==n-j+1) break;
		else{
		int p;		
		for(int i=j;i>=1;i--){
			if(b[i]!=n-j+i){
				p=i;
				break;
			}	
		}
		b[p]++;
		if(p+1<=j&&b[p]<n-j+p){
		for(int i=p+1;i<=j;i++){
		b[i]=b[i-1]+1;	
		}	
		}
		}	
		}
		for(int i=1;i<=j;i++) b[i]=i;
	}
	cout<<ans%998244353;
	return 0;
}


