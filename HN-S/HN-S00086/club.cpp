#include<bits/stdc++.h> 
using namespace std;
int s[10][10001][4];
int s1[10][10001]={0};
int fz[10][3]={0};
int maxj=0;
int maxf=0;
int t,n[10001];
int main()
{	
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    for(int i=1;i<10;i++){
    	for(int j=1;j<10001;j++){
    		s1[i][j]=0;
		}
	}
	for(int i=1;i<10;i++){
    	for(int j=1;j<3;j++){
    		fz[i][j]=0;
		}
	}
	cin>>t;
	int iw=1;
	while(iw<=t) {		
		cin>>n[iw];
		for(int j=1;j<=n[iw];j++){
			for(int f=1;f<=3;f++){
				cin>>s[iw][j][f];								
			}			
		}
		iw++;
	}		
	int max;
		long long sum[10]={0};
	for(int i=1;i<=t;i++){		 
		while(fz[i][1]+fz[i][2]+fz[i][3]<n[i]){			
	    max=INT_MIN;
			maxj=0;
			maxf=0;
		for(int j=1;j<=n[i];j++){
			for(int f=1;f<=3;f++){
				if(s[i][j][f]>max&&s1[i][j]<1&&fz[i][f]<n[i]/2){
					max=s[i][j][f];
					maxj=j;
					maxf=f;					
				}
			}
		}	
		sum[i]+=max;
		
		s1[i][maxj]++;		
		fz[i][maxf]++;
		}
		
	}
	for(int i=1;i<=t;i++){
		cout<<sum[i]<<endl;
	}
	return 0;

}
