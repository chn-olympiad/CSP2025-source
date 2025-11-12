#include<bits/stdc++.h>
using namespace std;
int n,k,a[1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool x=true,y=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){x=false;}
		if(a[i]!=0&&a[i]!=1){y=false;}
	}
	if(x&&k==0){
		if(n==1){cout<<1;}else{cout<<n/2;}
	}else if(y){
		if(k==1){
			int s=0;
			if(n==1){cout<<a[1];}else{
				for(int i=1;i<=n-1;i++){
					if(a[i]!=a[i+1]){
						s++;
						i++;
					}
				}
				cout<<s;
			}
		}else{
			int s=0;
			if(n==1){cout<<1;}else{
				for(int i=1;i<=n-1;i++){
					if(a[i]==a[i+1]){
						s++;
						i++;
					}
				}
				cout<<s;
			}
		}		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
