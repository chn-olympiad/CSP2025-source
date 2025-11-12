#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		int n,sum=0;
		int as=0,bs=0,cs=0;
		cin>>n;
		int a[n]={};
		int b[n]={};
		int c[n]={};
		for(int j = 0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>=max(b[j],c[j])){
				if(as>=n/2){
					if(b[j]>=c[j]){
						bs++;
						sum+=b[j]; 
					}
					else{
						cs++;
						sum+=c[i];
					}
					continue;
				}
				as++;
				sum+=a[j];
			}
			else if(b[j]>=max(a[j],c[j])){
				if(bs>=n/2){
					if(a[j]>=c[j]){
						as++;
						sum+=a[j]; 
					}
					else{
						cs++;
						sum+=c[i];
					}
					continue;
				}
				bs++;
				sum+=b[j];
			}
			else if(c[j]>=max(a[j],b[j])){
				if(as>=n/2){
					if(a[j]>=b[j]){
						as++;
						sum+=a[j]; 
					}
					else{
						bs++;
						sum+=b[i];
					}
					continue;
				}
				cs++;
				sum+=c[j];
			}
		}
		cout<<sum<<endl;//cout×ÜÖµ 
	}
	return 0;
} 

