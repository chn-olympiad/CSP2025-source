#include<bits/stdc++.h>
using namespace std;
int n,k,start,ans,startf,n_g;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	//int sum=0;
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){int g;
		cin>>g;a[i]=g;
		if(a[i]==k) start=i,ans++;
		if(a[i]==k&&startf==0) startf=i;
	}
	for(int i=1;i<=n;i++){int g;
		if(k!=0&&a[i]==0) a[i]=-1;
	}
	//if(k==0) cout<<n;
	//else{
	int tmp=start;
		for(int i=start-1;i>=1;i--){
			if(a[i]==k){
				for(int j=i+1;j<start-1;j++){//cout<<"hi";
					if((a[j]^a[j+1])==k){
//						cout<<j<<endl;
						j=j+2;ans++;
					}else if(a[j+1]==-1){
						if((a[j]^a[j+2])==k){//cout<<i;
							j=j+3;ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<startf-1;i++){
			if((a[i]^a[i+1])==k){//cout<<i<<(a[i]^a[i+1]);
				i=i+2;ans++;//cout<<(a[i]^a[i+1]);
			}else if(a[i+1]==-1){
				if((a[i]^a[i+2])==k){//cout<<i;
					i=i+3;ans++;
				}
			}
		} 
		for(int i=start+1;i<n;i++){//[start+1,n]
			if((a[i]^a[i+1])==k){//cout<<i;
				i=i+2;ans++;
			}else if(a[i+1]==-1){
				if((a[i]^a[i+2])==k){//cout<<i;
					i=i+3;ans++;
				}
			}
		}
	//}
	cout<<ans;
	return 0;
}
