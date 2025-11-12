#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long sum=0,c1[1000]={},cc1=0,c2[1000]={},cc2=0,c3[1000]={},cc3=0,p[1000];
		long long n,a[100][100]={};
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			
			}
		} 
		long long b[10000]={};
		for(int i=1;i<=n;i++){
			b[i]=max(a[i][1],max(a[i][2],a[i][3]));
			if(b[i]==a[i][1]){
			
				cc1++;
				if(cc1<=n/2){
				
					c1[i]=b[i];
					
				}
				else{
					int min=i;
					c1[i]=b[i];
					for(int j=1;j<=i;j++){
						if(c1[j]-max(a[j][2],a[j][3])<c1[min]-max(a[min][2],a[min][3])&&c1[j]>0)min=j;
					}
				c1[min]=-1;
			
					b[min]=max(a[min][2],a[min][3]);
						cc1--;
						if(b[min]==a[min][2]){
							c2[min]=b[min];
							cc2++;
							p[i]=2;
						}
						if(b[min]==a[min][3]){
							c3[min]=b[min];
							cc3++;
							p[i]=3;
						}
				}
				}
			if(b[i]==a[i][2]){
				cc2++;
				p[i]=2;
				if(cc2<=n/2){
					
					c2[i]=b[i];
				}
				else{
					int min=i;
					c2[i]=b[i];
					for(int j=1;j<=i;j++){
						if(c2[j]-max(a[j][1],a[j][1])<c2[min]-max(a[min][1],a[min][3])&&c2[j]>=0)min=j;
					}
				
					c2[min]=-1;
					
					b[min]=max(a[min][1],a[min][3]);
						cc2--;
						if(b[min]==a[min][1]){
							c1[min]=b[min];
							cc1++;
							
							
						}
						if(b[min]==a[min][3]){
							c3[min]=b[min];
							cc3++;
							
						}
						
				}
			}
			if(b[i]==a[i][3]){
				cc3++;
				p[i]=3;
				if(cc3<=n/2){
					
					c3[i]=b[i];
				}
				else{
					int min=i;
					c3[cc3]=b[i];
					for(int j=1;j<=i;j++){
						if(c3[j]-max(a[j][2],a[j][1])<c3[min]-max(a[min][2],a[min][1])&&p[i]==3)min=j;
					}
					c3[min]=-1;
					b[min]=max(a[min][1],a[min][2]);
					cc3--;
					if(b[min]==a[min][2]){
							c2[min]=b[min];
							cc2++;
						
						}
						if(b[min]==a[min][1]){
							c1[min]=b[min];
							cc1++;
							
						}
				}
			}
			
		}
		for(int i=1;i<=n;i++){
			sum+=b[i];
	
		}
		cout<<sum<<endl;
	
		} 
	
	return 0;
}
