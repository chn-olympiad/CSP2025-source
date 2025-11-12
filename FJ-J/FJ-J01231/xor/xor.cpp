#include<bits/stdc++.h>
using namespace std;
const int N=1e7+7;
//T3 :10 pts teshuxingzhiA
//注意 freopen用了吗 ll要开吗 N大小够吗 
int n,k,a[N];bool haveA=1,haveB=1,haveC=1;
bool f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			haveA=0;
		}
		if(a[i]!=1&&a[i]!=0){
			haveB=0;
		}
		if(a[i]>255)haveC=0;
	}
	if(haveA){
		cout<<n/2;
		return 0;
	}
	if(haveB){
		if(k==0){
			int ans=0;
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1]){
					ans++;
					i++;
					continue;
				}
			}
			cout<<ans;
			return 0;
		}
		else{
			int ans=0;
			for(int i=1;i<n;i++){
				if(a[i]!=a[i+1]){
					ans++;
					i++;
					continue;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	if(haveC){
		int ans=0;  
		for(int add=1;add<n;add++){
			for(int l=1;l<n;l++){
				bool ok=1;
				for(int i=l;i<=l+add;i++){
					if(f[i]==1){
						ok=0;
						break;
					}
				}   
				if(ok==0)continue;
				if(add+l>n)break;
				int sum=a[l];
				for(int i=l;i<=l+add;i++){
					sum=(sum xor a[i]); 
					f[i]=1;
				}		
				if(sum==k){
					ans++;
				}		
			}	
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
/*  T_T  */
