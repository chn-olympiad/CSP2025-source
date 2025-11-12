#include<bits/stdc++.h>
using namespace std;

int n,a[500005],k,woshi0,wosh1,shu;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) woshi0++;
		if(a[i]==1) wosh1++;
	}
	
	if(k==1){
		int biaoji=-1;
		int biaoji2=0;
		for(int i=1;i<=n;i++){
			if(biaoji=-1){
				biaoji=a[i];
				biaoji2++;
			} else if(biaoji!=a[i]){
				shu++;
				biaoji2--;
				if(biaoji2==0){
					biaoji=-1;
				}
			}else if(biaoji==a[i]) biaoji2++;
		}
		cout<<shu;
		
		
	}
	if(k==0){
		if(n==2){
			cout<<2;
			return 0;
		} else if(n==1){
			cout<<1;
			return 0;
		}
		int biaoji=-1;
		int biaoji2=0;
		for(int i=1;i<=n;i++){ 
			if(biaoji=-1){
				biaoji=a[i];
				biaoji2++;
			} else if(biaoji!=a[i]){
				shu++;
				biaoji2--;
				if(biaoji2==0){
					biaoji=-1;
				}
			}else if(biaoji==a[i]) biaoji2++;
		}
		shu+=biaoji2;
		cout<<shu;
		
	}
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
} 
