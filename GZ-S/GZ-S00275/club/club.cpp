//GZ-S00275 贵阳市第十九中学 杨雅琪 
#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005][4],d[200005][4];
int d1[3][200005],d2[3][200005],d3[3][200005],b[4],sum,maxper,maxpos;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		for(int k=0;k<3;k++){
			b[k]=0;
		}
		sum=0;
		cin>>n;
		for(int j=0;j<n;j++){
			int maxx=0;
			for(int k=0;k<3;k++){
				cin>>a[j][k];
				d[j][k]=a[j][k];
				if(a[j][k]>maxx){
					maxper=j;
					maxpos=k;
					maxx=a[j][k];
				}
			}
			if(b[maxpos]*2+2<=n){
				sum+=a[maxper][maxpos];
				b[maxpos]++;	
				if(maxpos==0){
					d1[0][b[maxpos]-1]=a[maxper][maxpos];
					d1[1][b[maxpos]-1]=maxper;
				}
				else if(maxpos==1){
					d2[0][b[maxpos]-1]=a[maxper][maxpos];
					d2[1][b[maxpos]-1]=maxper;
				}
				else{
					d3[0][b[maxpos]-1]=a[maxper][maxpos];
					d3[1][b[maxpos]-1]=maxper;
				}
			}
			else{
				if(maxpos==0){
					int mi=200000;
					int minpos;
					for(int l=0;l<b[maxpos];l++){
						if(d1[0][l]<mi){
							mi=d1[0][l];
							minpos=l;
						}
					}
					if(a[maxper][maxpos]>d1[0][minpos]){
						sum-=d1[0][minpos];
						d1[0][minpos]=a[maxper][maxpos];
						d1[1][minpos]=maxper;
						if(a[d1[1][minpos]][1]>=a[d1[1][minpos]][2]){
							b[1]+=1;
							sum+=a[d1[1][minpos]][1];
							d2[0][b[1]-1]=a[d1[1][minpos]][1];
							d2[1][b[1]-1]=d1[1][minpos];
						}
						else{
							b[2]+=1;
							sum+=a[d1[1][minpos]][1];
							d3[0][b[1]-1]=a[d1[1][minpos]][1];
							d3[1][b[1]-1]=d1[1][minpos];
						}
					}
				}
				if(maxpos==1){
					int mi=200000;
					int minpos;
					for(int l=0;l<b[maxpos];l++){
						if(d2[0][l]<mi){
							mi=d2[0][l];
							minpos=l;
						}
					}
					if(a[maxper][maxpos]>d2[0][minpos]){
						sum-=d2[0][minpos];
						d2[0][minpos]=a[maxper][maxpos];
						d2[1][minpos]=maxper;
						if(a[d2[1][minpos]][0]>=a[d2[1][minpos]][2]){
							b[0]+=1;
							sum+=a[d2[1][minpos]][1];
							d1[0][b[1]-1]=a[d2[1][minpos]][1];
							d1[1][b[1]-1]=d2[1][minpos];
						}
						else{
							b[2]+=1;
							sum+=a[d1[1][minpos]][1];
							d3[0][b[1]-1]=a[d2[1][minpos]][1];
							d3[1][b[1]-1]=d2[1][minpos];
						}
						
					}
				}
				if(maxpos==2){
					int mi=200000;
					int minpos;
					for(int l=0;l<b[maxpos];l++){
						if(d3[0][l]<mi){
							mi=d3[0][l];
							minpos=l;
						}
					}
					if(a[maxper][maxpos]>d3[0][minpos]){
						sum-=d3[0][minpos];
						sum+=a[maxper][maxpos];
						d3[0][minpos]=a[maxper][maxpos];
						d3[1][minpos]=maxper;
						if(a[d3[1][minpos]][0]>=a[d3[1][minpos]][1]){
							b[0]+=1;
							sum+=a[d3[1][minpos]][1];
							d1[0][b[1]-1]=a[d3[1][minpos]][1];
							d1[1][b[1]-1]=d3[1][minpos];
						}
						else{
							b[1]+=1;
							sum+=a[d1[1][minpos]][1];
							d2[0][b[1]-1]=a[d3[1][minpos]][1];
							d2[1][b[1]-1]=d3[1][minpos];
						}
						
					}
				}
			}
		}
		cout<<sum<<endl;
	}
}
