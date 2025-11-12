#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt1=0,cnt11=0,cnt0=0;
	bool lian=false;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt1++;
			if(!lian){
				lian=true;
			}else{
				if(a[i-1]==1){
					lian=false;
					cnt11++;
				}
			}
		}
		if(a[i]==0) cnt0++;
		
	}
	if(k>1){
		cout<<0;
	} else if(k==1){
		cout<<cnt1;
	}else{
		cout<<cnt0+cnt11;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
