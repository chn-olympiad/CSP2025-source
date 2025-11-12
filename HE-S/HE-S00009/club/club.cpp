#include<bits/stdc++.h>
using namespace std;
int t,n,h=0,a[3];
int p(int n){
	int m=-1,k;
	for(int i=0;i<3;i++){
		if(a[i]>m){
			k=i;
			m=a[i];
		}
	}
	return k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int b[3]={0,0,0};
		for(int j=0;j<n;j++){
			cin>>a[0]>>a[1]>>a[2];
	 	if(b[0]<n/2&&b[1]<n/2&&b[2]<n/2) {
				h+=a[p(0)];
				b[p(0)]++;
			}
			else if(b[0]>=n/2&&b[1]>=n/2)
			{
				h+=b[2];
				b[2]++;	
			}
			else if(b[1]>=n/2&&b[2]>=n/2)
			{
				h+=b[1];
				b[1]++;	
			}
			else if(b[0]>=n/2&&b[2]>=n/2)
			{
				h+=b[1];
				b[1]++;	
			}
			else if(b[0]>=n/2){
				if(a[1]>a[2]){
					b[1]++;
					h+=a[1];
				}else if(a[1]<a[2]){
					b[2]++;
					h+=a[2];
				}else if(a[1]==a[2]){
					if(b[1]>b[2]){
						b[2]++;
						h+=a[2];
					}else if(b[1]<b[2]){
						b[1]++;
						h+=a[1];
					}
				}
			}else if(b[1]>=n/2){
				if(a[2]>a[0]){
					b[2]++;
					h+=a[2];
				}else if(a[2]<a[0]){
					b[0]++;
					h+=a[0];
				}else if(a[2]==a[0]){
					if(b[0]>b[2]){
						b[2]++;
						h+=a[2];
					}else if(b[0]<b[2]){
						b[1]++;
						h+=a[1];
					}
				}
			}else if(b[2]>=n/2){
				if(a[1]>a[0]){
					b[1]++;
					h+=a[1];
				}else if(a[1]<a[0]){
					b[0]++;
					h+=a[0];
				}else if(a[1]==a[0]){
					if(b[0]>b[1]){
						b[1]++;
						h+=a[1];	
					}else if(b[0]<b[1]){
						b[0]++;
						h+=a[0];
					}
				}
			}
			else if(b[0]>=n/2&&b[1]>=n/2)
			{
				h+=b[2];
				b[2]++;	
			}
			else if(b[1]>=n/2&&b[2]>=n/2)
			{
				h+=b[1];
				b[1]++;	
			}
			else if(b[0]>=n/2&&b[2]>=n/2)
			{
				h+=b[1];
				b[1]++;	
			}
		} 
		cout<<h<<endl;
		h=0;
	}
	return 0;
} 
