#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	for(;t>0;t--){
		int n=0;
		cin>>n;
		int x[n][4]={};
		for(int i=0;i<n;i++){
			cin>>x[i][0];
			cin>>x[i][1];
			cin>>x[i][2];
			if(x[i][0]>=x[i][1]&&x[i][0]>=x[i][2])
				x[i][3]=1;
			if(x[i][1]>=x[i][0]&&x[i][1]>=x[i][2])
				x[i][3]=2;
			if(x[i][2]>=x[i][0]&&x[i][2]>=x[i][1])
				x[i][3]=3;
		}
		int a=0,b=0,c=0,sum=0;
		for(int i=0;i<n;i++){
			if(x[i][3]==1){
				a+=1;
				sum+=x[i][0];
			}
			if(x[i][3]==2){
				b+=1;
				sum+=x[i][1];
			}
			if(x[i][3]==3){
				c+=1;
				sum+=x[i][2];
			}
		}
		if(a<=n/2&&b<=n/2&&c<=n/2){
			cout<<sum<<endl;
		}else{
			while(a>n/2||b>n/2||c>n/2){
				bool aa=a>n/2,bb=b>n/2,cc=c>n/2;
				int num[n][3]={},nu=0;
				if(aa){
					for(int i=0;i<n;i++){
						if(x[i][3]==1){
							num[nu][0]=i+1;
							if(x[i][1]>=x[i][2]){
								num[nu][1]=2;
								num[nu][2]=x[i][0]-x[i][1];
							}else{
								num[nu][1]=3;
								num[nu][2]=x[i][0]-x[i][2];
							}
							nu++;
						}
					}
					int dj=num[0][2],zy=num[0][1],bh=num[0][0]-1;
					for(int i=1;i<n&&num[i][0]!=0;i++){
							if(dj>num[i][2]){
								dj=num[i][2],zy=num[i][1],bh=num[i][0]-1;
							}	
					}
					x[bh][3]=zy;
					a-=1;
				}else if(bb){
					for(int i=0;i<n;i++){
						if(x[i][3]==2){
							num[nu][0]=i+1;
							if(x[i][0]>=x[i][2]){
								num[nu][1]=1;
								num[nu][2]=x[i][1]-x[i][0];
							}else{
								num[nu][1]=3;
								num[nu][2]=x[i][1]-x[i][2];
							}
							nu++;
						}
					}
					int dj=num[0][2],zy=num[0][1],bh=num[0][0]-1;
					for(int i=1;i<n&&num[i][0]!=0;i++){
							if(dj>num[i][2]){
								dj=num[i][2],zy=num[i][1],bh=num[i][0]-1;
							}	
					}
					x[bh][3]=zy;
					b-=1;
				}else if(cc){
					for(int i=0;i<n;i++){
						if(x[i][3]==3){
							num[nu][0]=i+1;
							if(x[i][1]>=x[i][0]){
								num[nu][1]=2;
								num[nu][2]=x[i][2]-x[i][1];
							}else{
								num[nu][1]=1;
								num[nu][2]=x[i][2]-x[i][0];
							}
							nu++;
						}
					}
					int dj=num[0][2],zy=num[0][1],bh=num[0][0]-1;
					for(int i=1;i<n&&num[i][0]!=0;i++){
							if(dj>num[i][2]){
								dj=num[i][2],zy=num[i][1],bh=num[i][0]-1;
							}	
					}
					x[bh][3]=zy;
					c-=1;
				}
			}
			sum=0;
			for(int i=0;i<n;i++){
				if(x[i][3]==1){
					sum+=x[i][0];
				}
				if(x[i][3]==2){
					sum+=x[i][1];
				}
				if(x[i][3]==3){
					sum+=x[i][2];
				}
			}
			cout<<sum<<endl;
		}
	}
	
	return 0;
}
