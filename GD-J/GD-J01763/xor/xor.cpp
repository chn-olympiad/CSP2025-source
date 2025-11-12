#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,K;
	cin>>n>>K;
	bool f=0,f2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
		if(a[i]!=0&&a[i]!=1) f2=1;
	}
	if(f2){
		cout<<0;
	}
	else if(f){
		if(K==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					++ans;
				}
			}
			cout<<ans<<endl;
		}
		else if(K==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					++ans;
				}
				else{
					int t=0;
					while(a[i]==1){
						++t,++i;
					}
					ans+=t/2;
				}
			}
			cout<<ans;
		}
	}
	else{
		if(K==1){
			cout<<n;
		}
		else if(K==0){
			cout<<n/2;
		}
		else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
