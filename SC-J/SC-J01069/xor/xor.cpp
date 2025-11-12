#include<bits/stdc++.h>
using namespace std;
int a[500005],f[500005];
int l[500005],r[500005];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) l[i]=i,r[i]=i;
		else{
			int x=a[i];
			for(int j=i+1;j<=n;j++){
				x=(x^a[j]);
				if(x==k){
					l[i]=i,r[i]=j;
					break;
				}
			}
		}
		
	}
	int ans=0,ansi=1;
	f[1]=1;
	for(int i=2;i<=n;i++){
		if(l[i]!=0){
			if(l[i]>r[ansi]){
				f[i]=f[ansi]+1;
			}
			else f[i]=1;
		}
		if(f[i]>ans){
			ans=f[i];
			ansi=i;
		}
	}
	cout<<ans;
	return 0;
}