#include <bits/stdc++.h>
using namespace std;
int t,n,a[500005],b[500005],c[500005],sum=0,xuesheng[500005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){

		cin>>n;
		sum=0;
		for(int q=1;q<=n;q++){
			a[q]=b[q]=c[q]=0;
			xuesheng[q]=0;	
		}
		int x=0,y=0,z=0,xl=1,yl=1,zl=1;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];			
			if((x+1)<=n/2 && (y+1)<=n/2 && (z+1)<=n/2){
			xuesheng[j]=max(c[j],max(a[j],b[j]));
			sum+=xuesheng[j];
			if(xuesheng[j]==a[j]){
				x++;
			}else if(xuesheng[j]==b[j]){
				y++;
			}else{
				z++;
			}					
			}else if((x+1)>n/2 && a[j]==max(c[j],max(a[j],b[j]))){
				xuesheng[j]=max(b[j],c[j]);
				for(int k=xl;k<=j;k++){
					xl++;
					if(xuesheng[k]+xuesheng[j]<b[k]+a[j] || xuesheng[k]+xuesheng[j]<c[k]+a[j]){
						xuesheng[j]=a[j];
						sum=sum-xuesheng[k]+max(b[k],c[k])+xuesheng[j];
						xuesheng[k]=max(b[k],c[k]);						
						if(xuesheng[k]==b[k]){
							y++;
						}else{
							z++;
						}
						break;
					}
				}
				
			}else if((y+1)>n/2 && b[j]==max(c[j],max(a[j],b[j]))){
				xuesheng[j]=max(a[j],c[j]);				
				for(int k=yl;k<=j;k++){
					yl++;
					if(xuesheng[k]+xuesheng[j]<a[k]+b[j] || xuesheng[k]+xuesheng[j]<c[k]+b[j]){
						xuesheng[j]=b[j];
						sum=sum-xuesheng[k]+max(a[k],c[k])+xuesheng[j];
						xuesheng[k]=max(a[k],c[k]);						
						if(xuesheng[k]==a[k]){
							x++;
						}else{
							z++;
						}
						break;
					}
				}				
			}else if((z+1)>n/2 && c[j]==max(c[j],max(a[j],b[j]))){
				xuesheng[j]=max(a[j],b[j]);
				for(int k=zl;k<=j;k++){
					zl++;
					if(xuesheng[k]+xuesheng[j]<a[k]+c[j] || xuesheng[k]+xuesheng[j]<b[k]+c[j]){
						xuesheng[j]=c[j];
						sum=sum-xuesheng[k]+max(a[k],b[k])+xuesheng[j];
						xuesheng[k]=max(a[k],b[k]);						
						if(xuesheng[k]==a[k]){
							x++;
						}else{
							y++;
						}
						break;
					}
				}				
			}else{
				xuesheng[j]=max(c[j],max(a[j],b[j]));
				sum+=xuesheng[j];
				if(xuesheng[j]==a[j]){
					x++;
				}else if(xuesheng[j]==b[j]){
					y++;
				}else{
					z++;				
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
