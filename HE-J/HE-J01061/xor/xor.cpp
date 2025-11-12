#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
int a2[500010]={};
int b2[500010]={};
int x[500010]={};
long long h[500010]={};
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long aans=0;
	long long ng=0;
	
	for(int p=1;p<=n;++p){
		long long yg;
		cin>>yg;
		h[p]=yg;
		if(ng==0){
			ng=yg;
			if(ng==m){
				ng=0;
				aans++;
			}
		}
		else{
			
			int i=1;
			while(ng){
				a2[i]=ng%2;
				ng/=2;
				i++;
				//cout<<a2[i];
			}
			//cout<<' ';
			int j=1;
			while(yg){
				b2[j]=yg%2;
				yg/=2;
				j++;
				//cout<<b2[i];
			}
			//cout<<endl;
			for(int k=1;k<=max(i,j);k++){
				if(a2[k]==b2[k]){
					x[k]=0;
				}
				else{
					x[k]=1;
				}
				
			}
			long long ans=0;
			int k=0;
			for(int u=1;u<=max(i,j);++u){
				ans+=x[u]*pow(2,k);
				k++;
			}
			//cout<<ans<<' ';
			yg=ans;
			if(yg==m){
				ng=0;
				aans++;
			}
			else{
				ng=yg;
			}
			//ng=yg
		}
		
		
		}
	if(aans==0){
		for(int i=1;i<=n;++i){
			if(h[i]==m){
				aans++;
			}
		}
	}
	cout<<aans;
	return 0;
}
