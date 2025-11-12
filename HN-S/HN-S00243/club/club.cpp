#include<bits/stdc++.h>
using namespace std;
int nm(){
	long long a[3][20000],c[20000],d[3][20000];
	int n,x=0,y,z,ans=0,ans1=0;
	int b[3]={0,0,0};
	cin>>n;
	for(int i=0;i<n;++i){
		x=0;
		y=0;
		
		cin>>a[0][i]>>a[1][i]>>a[2][i];
		
		for(int l=0;l<3;l++){
			
			if(a[l][i]>x){
				x=a[l][i];
				y=l;
				d[l][i]=1;	
			}
		}
		b[y]++;
		ans=x+ans;

	}

	for(int k=0;k<3;k++){
	
			if(b[k]>n/2){
			
				z=b[k]-n/2;
				y=k;
				
				for(int i=0;i<n;++i){
				ans1=0;
					for(int l=0;l<3;++l){
						
						if(a[l][i]>=ans1&&l!=y&&d[y][i]==1){
					
							
						c[i]=a[y][i]-a[l][i];
						
						ans1=a[l][i];
						}
					}
						
			}
				for(int i=0;i<n;++i){
					for(int l=i;l<n;l++){
						if(c[i]>c[l]){
								x=c[i];
								c[i]=c[l];
								c[l]=x;
							
						}
					}
				}
				for(int i=0;i<z;++i){
			
					ans=ans-c[i];
				}
				break;	
			}
		}
	
	
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club,out","w",stdout);
	int t=0;
	int a[2026];
	cin>>t;
	for(int i=0;i<t;++i){
	a[i]=nm();
	}
	for(int i=0;i<t;++i){
		cout<<a[i]<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

