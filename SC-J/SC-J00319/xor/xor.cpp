#include<bits/stdc++.h>
using namespace std;
long long n,llk;
long long a[500010];  
bool s[500010];
long long cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>llk;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==llk){
			cnt++;
			s[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-j+1;j++){
			int l=j,r=j+i;
			int u=a[l];
			int f=0;
			if(s[l]){
			    f=1; 
			}
			for(int k=l+1;k<=r;k++){
				if(s[k]==1){
					f=1;
					break;
				}
				u=u^a[k];
			}
			if(u==llk){
				if(f==0){
					for(int k=l;k<=r;k++){
					s[k]=1;
					
					}
					cnt++;	
				}
			}
		}
	}
	cout<<cnt;
	return 0;
} 