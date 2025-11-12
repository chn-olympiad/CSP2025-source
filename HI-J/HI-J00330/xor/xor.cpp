#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,cnt,k;
long long a[N]; 
bool v[N],flag=false;
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			flag=1;
		}
		if(a[i]!=1 || a[i]!=0){
			flag=true;
		}
	}
	if(!flag){
		if(m==1 || m!=0){	
		}
	}
	else{
		if(!flag){
			cout<<n/2;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
			}
			for(int j=1;j<=n;j++){
				if(a[j]=1||a[j]!=0){
					ans++;
					j+=2;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		k=0;
		for(int l=1;l<=i;l++){
			k^=a[l];
		}
		for(int j=1;j<=(n-i+1);j++){
				
		}
	}
	cout<<ans-1;
	return 0;
} 
