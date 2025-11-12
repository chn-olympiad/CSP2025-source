#include <bits/stdc++.h>
using namespace std;
int a[500005]={},f[500005]={},n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >>k;
	char status='A';
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]!=1) status='B';
		if(a[i]>=2) status='N';
	}
	if(status=='A'){
		cout <<(int)(n/2) <<endl;
	}else if(status=='B'){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i-1]==1){
					if(f[i-1]==0){
						f[i]=1,f[i-1]=1;
						ans++;
					}
				}
			}
			cout <<ans <<endl;
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout <<ans <<endl;
		}
	}else{
		cout <<0 <<endl;
	}
	return 0;
}
