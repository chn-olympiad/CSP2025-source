#include <bits/stdc++.h>
using namespace std;

	int a[10];
	int b1[100010];
	int b2[100010];
	int b3[100010];
int t,n;

int xx(){

	int min1,min2,min3;
	cin>>n;
	for(int i=1;i<=6*n;i++){
		if(i<=n){ cin>>b1[i]>>b2[i]>>b3[i];
		min1=min(min1,b1[i]);
		min2=min(min2,b2[i]);
		min3=min(min3,b3[i]);
		
		
		}
		else if(i>n&&i<=2*n){
			b2[i]=b3[i-n];
			b3[i]=b2[i-n];
			b1[i]=b1[i-n];
		}
		else if(i>2*n&&i<=3*n){
			b1[i]=b2[i-2*n];
			b2[i]=b1[i-2*n];
			b3[i]=b3[i-2*n];
		}
		else if(i>3*n&&i<=4*n){
			b1[i]=b3[i-3*n];
			b3[i]=b1[i-3*n];
			b2[i]=b2[i-3*n];
		}
		else if(i>4*n&&i<=5*n){
			b1[i]=b2[i-4*n];
			b2[i]=b3[i-4*n];
			b3[i]=b1[i-4*n];
		}
		else if(i>5*n&&i<=6*n){
			b1[i]=b3[i-5*n];
			b3[i]=b2[i-5*n];
			b2[i]=b1[i-5*n];
		}
	}

	int m=1;
	int k1=0,k2=0,k3=0;
	for(int i=1;i<=6*n;i++){
		cout<<b1[i]<<b2[i]<<b3[i]<<endl;
		int j=b1[i],k=b2[i],l=b3[i];
		if(j>=k&&j>=l&&j>min1){ 
			if(k1<n/2){
				a[m]+=j;
				k1++;
			}
			else {
				a[m]+=max(k,l);
			}
		}
		else if(k>=l&&k>min2){
			if(k2<n/2){
				a[m]+=k;
				k2++;
		
			}
			else a[m]+=max(j,l);
		}
		else {
			if(k3<n/2){
				a[m]+=l;
				k3++;
		
			}
			else a[m]+=max(k,j);
		}
		if(i%n==0) {
			m++;
			k1=0;k2=0;k3=0;
		}
	}
		
		int ans = max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6])))));
		a[1]=0;a[2]=0;a[3]=0;a[4]=0;a[5]=0;a[6]=0;
		for(int i=1;i<=6*n+6;i++){
			b1[i]=0;
			b2[i]=0;
			b3[i]=0;
		}
		return ans;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<xx()<<endl;
		
	}
	return 0;
}
