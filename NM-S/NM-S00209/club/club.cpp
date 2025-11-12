#include<bits/stdc++.h>
using namespace std;
int main (){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,b1=0,b2=0,b3=0,manyi=0;
	long long a1[9999999],a2[9999999],a3[9999999]
	cin>>t>>n;
	for(int j=1;j<t;j++){
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>a2[i]){
				if(a1[i]>a3[i]){
					b1+=1;
					if(n/2>b1){
						manyi+=a1[i];
				}
				if(a3[i]>a1[i]){
					b3+=1;
					if(n/2>b3){
						manyi+=a3[i];
					}
				}
			}
			if(a2[i]>a1[i]){
				b2+=1;
				if(n/2>b2){
					manyi+=a2[i];
				}
			}
		}
		cout<<manyi<<endl;
		manyi=0;
		b1=0;b2=0;b3=0;
		}
	}
	return 0;
}
