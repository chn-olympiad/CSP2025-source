#include<bits/stdc++.h>
using namespace std;
int n,k;
int t,a,ji;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		a=0;
		for(int i=1;i<=n;i++){
			cin>>t;
			if(t==0){
				if(a<2){
					ji++;
				}else{
					ji+=2;
					a=0;
				}
			}else{
				a++;
			}
		}
		cout<<ji;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			cin>>t;
			if(t==1){
				ji++;
			}
		}
		cout<<ji;
		return 0;
	}	                  
	return 0;
}