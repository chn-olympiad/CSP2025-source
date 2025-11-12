//GZ-S00011 付煜伟 贵阳市新世界学校 
#include<bits/stdc++.h>
using namespace std;
int t,n; 
int a[100001] = {},b[100001] = {},c[100001] = {};
int tx(int s,int a1,int b1,int c1){
	if(s>n){
		return 0;
	}
	int maxx = -1;
	if(a1<=n/2){
		int m = tx(s+1,a1+1,b1,c1)+a[s];
		if(m>maxx) maxx = m;
	} 
	if(b1<=n/2){
		int m = tx(s+1,a1,b1+1,c1)+b[s];
		
		if(m>maxx) maxx = m;
	} 
	if(c1<=n/2){
		int m = tx(s+1,a1,b1,c1+1)+c[s];
		if(m>maxx) maxx = m;
	}
	return maxx; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int t1 = 1;t1<=t;t1++){		
		cin>>n;
		for(int i = 1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
			}
		if(n>100000){
			int cnt = 0,a1 = 0,b1 = 0;
			for(int i = n;i>0;i--){
				if(a[i]>i && a1<n/2){
					cnt+=a[i];
					a1++;
				}else cnt+=i;
			}
			for(int i = 1;i<=n/2;i++) cout<<a[i];
		}else{
			
			cout<<tx(1,1,1,1)<<endl;	
		}
	
	}
	return 0;
}
