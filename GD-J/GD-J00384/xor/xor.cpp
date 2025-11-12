#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int t,ans,tem;
bool a1_a0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)a1_a0=true;
		if(a[i]==k)tem++;
	}
	if(a1_a0==false){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
					t=0;
				}else{
					if(t==1){
						ans++;
						t=0;
					}else{
						t=1;
					}
				}
			}
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}else{
		cout<<tem;
	}
	return 0;
} 
